//////////////////////////////////////////////////////////
//  AbsRebateFactory.cpp
//  Implementation of the Class AbsRebateFactory
//  Created on:      04-avril-2020 11:48:47
//  Original author: francois
///////////////////////////////////////////////////////////

#include "AbsRebateFactory.h"
#include "RebateManager.h"

namespace PolyCharge
{
	void AbsRebateFactory::registerFactory(std::string name, AbsRebateFactory* factoryp)
	{
		RebateManager& manager = RebateManager::getInstance();
		manager.addRebateFactory(name, factoryp);
	}
}