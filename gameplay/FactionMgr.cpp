#include "FactionMgr.h"

FactionMgr::FactionMgr()
{
	flist = new List<Faction>;
}

FactionMgr::~FactionMgr()
{
	delete flist;
}

void FactionMgr::add(Faction *f)
{
	flist->addElement(f);
}

void FactionMgr::addToFaction(SpaceObject *obj, std::string factionID)
{
	Faction *f=flist->find(factionID);
	if(f) f->addMember(obj);
}

void FactionMgr::unload(std::string id)
{
	flist->deleteElement(id);
}

Faction *FactionMgr::find(std::string id)
{
	return flist->find(id);
}
