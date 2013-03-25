/*
 * Scenario.h
 *
 *  Created on: Sep 9, 2008
 *      Author: sam
 */

#ifndef SCENARIO_H_
#define SCENARIO_H_

#include "FactionMgr.h"
#include "Player.h"
#include "../physics/gravitywell.h"
#include "../model/ModelMgr.h"
#include "../physics/objectmgr.h"


class Scenario
{
	std::string id;
public:
	Scenario();
	Scenario(std::string id, std::string file);
	virtual ~Scenario();
	bool load(std::string file);
	std::string getID();
};

#endif /* SCENARIO_H_ */
