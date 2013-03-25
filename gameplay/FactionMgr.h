#ifndef FACTIONMGR_H_
#define FACTIONMGR_H_

#include "../mm/singleton.h"
#include "../mm/list.h"
#include "Faction.h"

class FactionMgr : public Singleton<FactionMgr>
{
	List<Faction> *flist;
public:
	FactionMgr();
	virtual ~FactionMgr();
	void add(Faction *f);
	void addToFaction(SpaceObject *obj, std::string factionID);
	void unload(std::string id);
	Faction *find(std::string id);
};

#endif /*FACTIONMGR_H_*/
