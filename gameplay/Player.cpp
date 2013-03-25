#include "Player.h"

Player::Player()
{
	targeting = new TargetingSystem();
	radar = new Radar();
	playerStatus = new PlayerStatusIndicator();
}

Player::Player(std::string pid, std::string factionID, std::string model, Vector pos, Vector velocity, Quaternion q, double mass, float scale)
	:Ship(pid,factionID,model,pos,velocity,mass,scale)
{
	//top speed variable, change to desired top speed,
	topAccel = (24.0f*32767.0f)/mass;
	topTurnSpeed = 60.0f;
	thrustVecThreshold = 10.0f;

	//build(pid,model,pos,velocity,mass,scale);

	this->q=q;
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

	//Normalize vectors
	up.normalize();
	right.normalize();
	look.normalize();

	/*collisionID = "";
	lastCollision = 0;

	done=false;*/

	//targeting = new TargetingSystem(this);
	radar = new Radar(targeting, "radar");
	playerStatus = new PlayerStatusIndicator(this, "shipoutline");
	objectType="player";

	//beam = new BeamWeapon(this,Vector(-3.0f,-3.5f, 0.0f), 1.0f);

	weaponDisplay = new WeaponDisplay(this, "weaponpanel", "crosshair");
	weaponLauncher = new WeaponLauncher("Missile Launcher", 20, 20, 1000, this, Vector(0.15f*size*scale,-0.05f*size*scale,0.0f), Quaternion(0,0,0,1));
	weaponDisplay->setCurrentWeaponLauncher(weaponLauncher);

	view.createFromAxisAngle(0.0f,0.0f,0.0f,1.0f);
	tracking = false;
	syncCamera=true;
	beamOn = false;
	hits = 0;


	hull = 100.0f;

}

Player::~Player()
{
	delete radar;
	delete playerStatus;
	delete weaponDisplay;
	delete beam;
	beam = NULL;
}

std::string Player::getTarget()
{
	Object *t=targeting->getTarget();
	if(t)return t->getID();
	else return "";
}

std::string Player::getTargetID()
{
	return getTarget();
}

void Player::nextTarget()
{
	targeting->nextTarget();
}

void Player::prevTarget()
{
	targeting->prevTarget();
}

void Player::targetNearest()
{
	targeting->targetNearest();
}

void Player::targetNearestEnemy()
{
	targeting->targetNearestEnemy();
}

void Player::targetNearestAlly()
{
	targeting->targetNearestAlly();
}

void Player::targetNearestMissile()
{
	targeting->targetNearestMissile();
}

void Player::fireMissile()
{
	/*double m[16];
	getMatrix(m);
	std::ostringstream missileName;
	missileName <<"missile-"<<rand();
	std::string targetID = "";
	if(targeting->getTarget())targetID = targeting->getTarget()->getID();
	ObjectMgr::get().add(new Missile(missileName.str(),"missile",pos+right*0.1f*size*scale,velocity,50.0f,q,id,targetID,100.0f,0.3f));*/
	if(weaponLauncher) weaponLauncher->launch();
}

void Player::activateBeam()
{
	beam->activate();
}

void Player::toggleRadarZoom()
{
	radar->toggleZoom();
}

void Player::handleCollision(Object *other)
{
	if(!other)
	{
		hull-=GlobalTime::get().frameSec*75.0f;
		ParticleMgr::get().startExplosion("engine",36,0.1f,200.0f,700,pos,velocity, 5);
		if(hull<0.0f) done = true;
	}
	else if(other->getSource()!=id)
	{
		hits++;
		hull-=20;
		if(hull<=0)
		{
			done = true;

		}
	}

}

void Player::lookByAxisAngle(Vector axis, double angle)
{
	Quaternion n;
	n.createFromAxisAngle(axis, angle);
	view=n*view;
}

void Player::toggleTracking()
{
	if(tracking)tracking = false;
	else tracking = true;
}

bool Player::isTracking()
{
	return tracking;
}

void Player::extraRender()
{
	beam->render();
}

void Player::renderHUD()
{
	targeting->render();
	radar->render();
	playerStatus->render();
	weaponDisplay->render();
}

unsigned int Player::getHits()
{
	return hits;
}

double Player::getBeamEnergy()
{
	return beam->getEnergy();
}

double Player::getBeamHeat()
{
	return beam->getHeat();
}

void Player::action()
{
	if(tracking)track(targeting->getTargetID());

	Camera::get().setQuaternion(q*view);
	Camera::get().setPerspective();

	//Camera::get().setPos(pos+Camera::get().up*0.02f+Camera::get().look*0.07f);

	Camera::get().setPos(pos+Camera::get().up*-1.0f+Camera::get().look*-3.0f);

	//Camera::get().setPos(pos);

	Camera::get().translate();
	Camera::get().calcFrustum();
}
