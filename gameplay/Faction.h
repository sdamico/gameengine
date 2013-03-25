#ifndef FACTION_H_
#define FACTION_H_


#include "../mm/list.h"

class SpaceObject;

class Faction
{
	std::string id;
	std::string description;
	List<SpaceObject> *members;
public:
	Faction();
	Faction(std::string id, std::string description);
	virtual ~Faction();
	
	void setID(std::string id);
	void setDescription(std::string description);
	std::string getID();
	std::string getDescription();
	
	void addMember(SpaceObject *o);
	void removeMember(SpaceObject *o);
	void removeMember(std::string objectID);
};

#endif /*FACTION_H_*/
