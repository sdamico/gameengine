#ifndef OBJMGR_H
#define OBJMGR_H

#include "object.h"
#include "../mm/list.h"
#include "../mm/singleton.h"

class ObjectMgr : public Singleton<ObjectMgr>
{
	List<Object> *objectList;
	unsigned int numObj;
	bool aiEnabled;
	public:
	ObjectMgr();
	~ObjectMgr();
	void add(Object *obj);
	void handle();
	void render();
	void renderPlayer(bool showModel);
	void renderPlayerHUD();
	void positionPlayer();
	void unload(std::string id);
	void enableAI();
	void disableAI();
	//This a wise decision?
	List<Object> *getList();
	Object *detectCollision(Object *obj);
	Object *detectCollision(Vector x1, Vector x2);
	Object *find(std::string id);

	unsigned int getNumObj();

};

#endif

