#include "object.h"

Object::Object()
{
	right=Vector(1.0f,0.0f,0.0f);
	up=Vector(0.0f,-1.0f,0.0f);
	look=Vector(0.0f,0.0f,-1.0f);
	q.createFromAxisAngle(look.x,look.y,look.z,0.0f);
	source = "";
	objectType="object";
	done=false;
	collisionID = "";
	lastCollision = 0;
}

Object::~Object()
{
}

Object::Object(std::string id, std::string model, Vector pos, Vector velocity, double mass, float scale)
{
	objectType="object";
	build(id,model, pos,velocity,mass,scale);
}

void Object::build(std::string id, std::string model ,Vector pos, Vector velocity, double mass, float scale)
{
	this->model=model;
	//this->shader=shader;
	this->id=id;
	this->pos=pos;
	this->velocity=velocity;
	this->mass=mass;
	this->scale=scale;

	right=Vector(1.0f,0.0f,0.0f);
	up=Vector(0.0f,-1.0f,0.0f);
	look=Vector(0.0f,0.0f,-1.0f);
	q.createFromAxisAngle(up.x,up.y,up.z,-150.0f);
	source = "";
	collisionID = "";
	lastCollision = 0;
	done=false;
	acceleration=Vector();
	Model *mod = ModelMgr::get().find(model);
	if(mod) this->size=mod->getSphereRadius();
	else this->size = 1.0f;

	//Estimate I as a solid cylinder:
	this->momentOfInertia = 0.5f* this->mass * (this->size*this->scale) * (this->size*this->scale);
}

std::string Object::getID()
{
	return id;
}

std::string Object::getObjectType()
{
	return objectType;
}

std::string Object::getFactionID()
{
	return factionID;
}


//Now using RK4

void Object::move()
{
	Vector dp1 = velocity*(GlobalTime::get().frameSec);
	Vector dp2 = (velocity+dp1*.5)*(GlobalTime::get().frameSec);
	Vector dp3 = (velocity+dp2*.5)*(GlobalTime::get().frameSec);
	Vector dp4 = (velocity+dp3)*(GlobalTime::get().frameSec);
	//pos+=velocity*(GlobalTime::get().frameSec);
	pos+=(dp1/6+dp2/3+dp3/3+dp4/6);
	acceleration*=0;
}

void Object::accelerate()
{
	Vector dv1 = acceleration*(GlobalTime::get().frameSec);
	Vector dv2 = (acceleration+dv1*.5)*(GlobalTime::get().frameSec);
	Vector dv3 = (acceleration+dv2*.5)*(GlobalTime::get().frameSec);
	Vector dv4 = (acceleration+dv3)*(GlobalTime::get().frameSec);
	velocity+=(dv1/6+dv2/3+dv3/3+dv4/6);
}

void Object::applyForce(Vector force)
{
	acceleration+=force/mass;
}

bool Object::detectCollision(Object *other)
{
	if(other->getSource()!=id)
	{
		long curFrame = GlobalTime::get().getFrames();
		std::string otherID = other->getSource();
		if(otherID==collisionID || lastCollision!=curFrame)
		{
			Vector v=other->pos-pos;
			if(v.magnitude()<(((size*scale)/2)+((other->size*other->scale)/2)))
			{
				/*C3ds *mod = (C3ds*)ModelMgr::get().find(model);
				C3ds *mod2 = (C3ds*)ModelMgr::get().find(other->model);
				if(mod && mod2)
				{
					return mod->intersect(mod2,scale,other->scale, (FVector){v.x,v.y,v.z},q,other->q);
				}
				else
				{
					return true;
				}*/
				return true;
			}
		//if(sqrt((pos.x-other->pos.x)*(pos.x-other->pos.x)+(pos.y-other->pos.y)(pos.y-other->pos.y))<((size/2)+(other->size/2))) return true;
			collisionID=otherID;
			lastCollision=curFrame;
		}
	}
	return false;
}

Vector Object::detectCollision(Vector x1, Vector x2)
{
	if((x1-pos).magnitude())
	{
		double distance = ((x2-x1)%(x1-pos)).magnitude()/(x2-x1).magnitude();
		if(distance<(((size*scale)/2)))
		{
			/*C3ds *mod = (C3ds*)ModelMgr::get().find(model);
			x1=x1-pos;
			x2=x2-pos;
			if(mod)
			{
				Vector v;
				v=mod->intersect((FVector){x1.x,x1.y,x1.z},(FVector){x2.x,x2.y,x2.z},scale,q);
				return v;
			}*/
			return pos;
		}
	}
	return Vector();
}

void Object::renderMiniAtOrigin()
{
	glPushMatrix();

	double m[16];
	q.normalize().createMatrix(m);

	glMultMatrixd(m);
	glScalef(1.0f/size,1.0f/size,1.0f/size);

	ModelMgr::get().render(model);

	glPopMatrix();
}

void Object::renderAtOrigin()
{
	glPushMatrix();

	Quaternion fix;

	double m[16];
	q.normalize().createMatrix(m);

	glMultMatrixd(m);
//	glRotatef(180.0f,0.0f,0.0f,1.0f);


	glScalef(scale,scale,scale);

	ModelMgr::get().render(model);

	glPopMatrix();
}

void Object::render()
{
	if(Camera::get().sphereInFrustum(pos,size*scale))
	{
		glPushMatrix();
		//glLoadIdentity();
		glTranslated(pos.x,pos.y,pos.z);
		double m[16];
		q.createMatrix(m);
		glMultMatrixd(m);
		glScaled(scale,scale,scale);


		ModelMgr::get().render(model);


		glPopMatrix();
	}
}

void Object::extraRender()
{
}

void Object::rotateAxis(Vector axis, double angle)
{
	Quaternion rotate;
	rotate.createFromAxisAngle(axis.x,axis.y,axis.z,angle);
	q	= rotate*q;
	q=q.normalize();
	double m[16];
	q.createMatrix(m);
	up.x=m[0];
	up.y=m[1];
	up.z=m[2];
	right.x=m[4];
	right.y=m[5];
	right.z=m[6];
	look.x=m[8];
	look.y=m[9];
	look.z=m[10];
	up.normalize();
	right.normalize();
	look.normalize();
//	std::cout<<q.x<<" "<<q.y<<" "<<q.z<<" "<<q.w<<std::endl;
}

void Object::angularAccelerate()
{
	Vector dw1 = alpha*(GlobalTime::get().frameSec);
	Vector dw2 = (alpha+dw1*.5)*(GlobalTime::get().frameSec);
	Vector dw3 = (alpha+dw2*.5)*(GlobalTime::get().frameSec);
	Vector dw4 = (alpha+dw3)*(GlobalTime::get().frameSec);
	omega+=(dw1/6+dw2/3+dw3/3+dw4/6);
}

void Object::angularMove()
{
	Vector dt1 = omega*(GlobalTime::get().frameSec);
	Vector dt2 = (omega+dt1*.5)*(GlobalTime::get().frameSec);
	Vector dt3 = (omega+dt2*.5)*(GlobalTime::get().frameSec);
	Vector dt4 = (omega+dt3)*(GlobalTime::get().frameSec);
	//pos+=velocity*(GlobalTime::get().frameSec);
	Vector incr=(dt1/6+dt2/3+dt3/3+dt4/6);
	rotateAxis(incr.normalize(),RAD2DEG(incr.magnitude()));
	alpha*=0;
}

void Object::applyTorque(Vector t)
{
	alpha+=t/momentOfInertia;
}

void Object::action()
{
	double m[16];
	q.createMatrix(m);
	up.x=m[0];
	up.y=m[1];
	up.z=m[2];
	right.x=m[4];
	right.y=m[5];
	right.z=m[6];
	look.x=m[8];
	look.y=m[9];
	look.z=m[10];
	up.normalize();
	right.normalize();
	look.normalize();
}

Vector Object::getPos()
{
	return pos;
}


Vector Object::getUp()
{
	return up;
}


Vector Object::getRight()
{
	return right;
}

Vector Object::getVelocity()
{
	return velocity;
}

Vector Object::getOmega()
{
	return omega;
}

double Object::getMomentOfInertia()
{
	return momentOfInertia;
}

Vector Object::getLook()
{
	return look;
}

double Object::getSphereRadius()
{
	return size*scale;
}

double Object::getMass()
{
	return mass;
}

std::string Object::getSource()
{
	return source;
}

Quaternion Object::getQuaternion()
{
	return q;
}

void Object::getMatrix(double *m)
{
	q.createMatrix(m);
}

void Object::handleCollision(Object *other)
{
}
