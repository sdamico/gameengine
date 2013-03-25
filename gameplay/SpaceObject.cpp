#include "SpaceObject.h"

SpaceObject::SpaceObject()
{
}

SpaceObject::SpaceObject(std::string id, std::string factionID, std::string model, Vector pos, Vector velocity, double mass, float scale)
: Object(id, model, pos, velocity, mass, scale){
	//top speed variable, change to desired top speed
	topAccel = 10.0f;
	topTurnSpeed = 60.0f;
	thrustVecThreshold = 10.0f;

	objectType="spaceObject";

	this->factionID = factionID;
	FactionMgr::get().addToFaction(this, factionID);
	//build(id,model, pos,velocity,mass,scale);
}

SpaceObject::~SpaceObject()
{
}

//NOTE - NEED TO FIX LIKE WITH STOP AND MATCHVELOCITY
//180* BUG
void SpaceObject::track(std::string objectName)
{
	Object *o = ObjectMgr::get().find(objectName);

	if(o && objectName!=id)
	{
		//Vector from your position to object being tracked
		Vector delta = o->getPos()-pos;
		float seconds = ((-1*(velocity-o->getVelocity()).magnitude()+sqrt((velocity-o->getVelocity()).magnitude()*(velocity-o->getVelocity()).magnitude()+2*topAccel*delta.magnitude()))/(topAccel));
		float seconds2 = ((-1*(velocity-o->getVelocity()).magnitude()-sqrt((velocity-o->getVelocity()).magnitude()*(velocity-o->getVelocity()).magnitude()+2*topAccel*delta.magnitude()))/(topAccel));

		if(seconds2>seconds)seconds=seconds2;

		//float seconds = sqrt((delta.magnitude()*2.0f)/topAccel);
		//Distance 1s from now
		Vector shootFor = delta+(o->getVelocity()-velocity)*seconds;
		shootFor=shootFor.normalize();
		Vector axis = (look%shootFor).normalize();
		//std::cerr<<"youch!!!!\n";
		if(axis.magnitude()<0.01f)axis = up;

		float ang = look.angle(shootFor);

		if(ang<0.01f || fabs(ang-180.0f)<0.1f) axis = up;

		if(ang>0.0001f)
		{
			if(ang>topTurnSpeed*GlobalTime::get().frameSec)ang=topTurnSpeed*GlobalTime::get().frameSec;

			rotateAxis(axis,ang);
		}

		thrust(100.0f);

		//if(detectCollision(o)) done=true;
	}

}

void SpaceObject::track(Vector p)
{

	//Vector from your position to object being tracked
	Vector delta = p-pos;
	float seconds = ((-1*velocity.magnitude()+sqrt(velocity.magnitude()*velocity.magnitude()+2*topAccel*delta.magnitude()))/(topAccel));
	float seconds2 = ((-1*velocity.magnitude()-sqrt(velocity.magnitude()*velocity.magnitude()+2*topAccel*delta.magnitude()))/(topAccel));

	if(seconds2>seconds)seconds=seconds2;

	//float seconds = sqrt((delta.magnitude()*2.0f)/topAccel);
	//Distance 1s from now
	Vector shootFor = delta+(velocity*-1)*seconds;
	shootFor=shootFor.normalize();
	Vector axis = (look%shootFor).normalize();
	//std::cerr<<"youch!!!!\n";
	if(axis.magnitude()<0.01f)axis = up;

	float ang = look.angle(shootFor);

	if(ang<0.01f || fabs(ang-180.0f)<0.1f) axis = up;

	if(ang>0.0001f)
	{
		if(ang>topTurnSpeed*GlobalTime::get().frameSec)ang=topTurnSpeed*GlobalTime::get().frameSec;

		rotateAxis(axis,ang);
	}

	thrust(100.0f);

	//if(detectCollision(o)) done=true;


}

void SpaceObject::pointTowards(std::string objectName)
{
	Object *o = ObjectMgr::get().find(objectName);

	if(o && objectName!=id)
	{
		Vector delta = o->getPos()-pos;
		delta=delta.normalize();
		Vector axis = (delta%look).normalize();
		//std::cerr<<"youch!!!!\n";
		if(axis.magnitude()<0.01f)axis = up;

		float ang = look.angle(delta);


		if(ang<0.01f || fabs(ang-180.0f)<0.1f) axis = up;

		if(ang>0.0001f || (look.normalize()-delta.normalize()).magnitude()>1.0f)
		{

			if(ang>topTurnSpeed*GlobalTime::get().frameSec)ang=topTurnSpeed*GlobalTime::get().frameSec;

			rotateAxis(axis,ang);
		}
	}
}

void SpaceObject::matchVelocity(std::string objectName)
{
	Object *o = ObjectMgr::get().find(objectName);

	if(o && objectName!=id)
	{
		Vector deltaV = o->getVelocity()-velocity;
		if(deltaV.magnitude()>0.1f)
		{
			Vector thrustDir = deltaV.normalize();
			Vector axis = (look%thrustDir).normalize();
			if(axis.magnitude()<0.01f)axis = up;
			float ang = look.angle(thrustDir);
			if(ang<0.01f || fabs(ang-180.0f)<0.1f) axis = up;

			if(ang>0.0001f)
			{
				if(ang>topTurnSpeed*GlobalTime::get().frameSec)ang=topTurnSpeed*GlobalTime::get().frameSec;

				rotateAxis(axis,ang);
			}

			thrust(100.0f);
		}
	}
}

void SpaceObject::stop()
{
	if(velocity.magnitude())
	{
		Vector thrustDir=(velocity*-1).normalize();
		Vector axis = (look%thrustDir).normalize();
		if(axis.magnitude()<0.01f)axis = up;
		float ang = look.angle(thrustDir);
		if(ang<0.01f || fabs(ang-180.0f)<0.1f) axis = up;

		if(ang>0.0001f)
		{
			if(ang>topTurnSpeed*GlobalTime::get().frameSec)ang=topTurnSpeed*GlobalTime::get().frameSec;
			rotateAxis(axis,ang);
		}
		applyForce(thrustDir*topAccel*mass*0.8f);
	}
}

void SpaceObject::thrust(double percentage)
{
	applyForce(look*topAccel*mass*percentage*0.01);
}

void SpaceObject::handleCollision(Object *other)
{
	//done = true;
}

void SpaceObject::action()
{
	//applyForce(look*topAccel*mass);
}

std::string SpaceObject::getTargetID()
{
	return "";
}
