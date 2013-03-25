#include "Faction.h"
#include "SpaceObject.h"


Faction::Faction()
{
	members = new List<SpaceObject>;
	id="";
	description="";
}

Faction::Faction(std::string id, std::string description)
{
	members = new List<SpaceObject>;
	setID(id);
	setDescription(description);
}

Faction::~Faction()
{
	//Fix this problem - will try to delete already deleted objects from objectmgr....oooooppppssss
	//delete members;
}

void Faction::setID(std::string)
{
	this->id=id;
}

void Faction::setDescription(std::string)
{
	this->description=description;
}

std::string Faction::getID()
{
	return id;
}

std::string Faction::getDescription()
{
	return description;
}

void Faction::addMember(SpaceObject *o)
{
	members->addElement(o);
}

void Faction::removeMember(SpaceObject *o)
{
	if(o) members->deleteElement(o->getID());
}

void Faction::removeMember(std::string objectID)
{
	members->deleteElement(objectID);
}
