///////////////////////////////////////////////////////////
//  AbsPlanFactory.cpp
//  Implementation of the Class AbsPlanFactory
//  Created on:      04-avril-2020 11:48:47
//  Original author: francois
///////////////////////////////////////////////////////////

#include "AbsPlanFactory.h"
#include "PlanManager.h"

namespace PolyCharge
{
	void AbsPlanFactory::registerFactory(std::string name, AbsPlanFactory * factoryp)
	{
		PlanManager& manager = PlanManager::getInstance();
		manager.addPlanFactory(name, factoryp);
	}
}