///////////////////////////////////////////////////////////
//  RebateManager.cpp
//  Implementation of the Class RebateManager
//  Created on:      03-avr.-2020 15:44:39
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "RebateManager.h"

namespace PolyCharge
{
	RebateManager & RebateManager::getInstance(void)
	{
		static RebateManager instance;

		return instance;
	}

	void RebateManager::addRebateFactory(std::string factoryName, AbsRebateFactory * factoryp)
	{
		m_rebateFactorys[factoryName] = factoryp;
	}

	AbsRebateDecorator & RebateManager::createRebate(const std::string& RebateName, AbsSubscriptionPlan& plan, float percentRebate)
	{
		std::string newPlanName = plan.name() + "w" + RebateName;
		auto factoryPtr = m_rebateFactorys.find(RebateName);
		if (factoryPtr == m_rebateFactorys.end())
			throw std::range_error("No factory registered for the provided rebate name");

		auto newRebate = factoryPtr->second->createRebate(plan);
		if (newRebate == nullptr)
			throw std::logic_error("Unable to create rebate with registered factory");

		m_rebates[newPlanName] = RebatePointer(newRebate);

		return *newRebate;
	}

	RebateTypeIterator RebateManager::rebateType_begin()
	{
		return RebateTypeIterator(m_rebateFactorys.begin());
	}

	RebateTypeIterator RebateManager::rebateType_end()
	{
		return RebateTypeIterator(m_rebateFactorys.end());
	}

	RebateTypeConstIterator RebateManager::rebateType_cbegin() const
	{
		return RebateTypeConstIterator(m_rebateFactorys.cbegin());
	}

	RebateTypeConstIterator RebateManager::rebateType_cend() const
	{
		return RebateTypeConstIterator(m_rebateFactorys.cend());
	}
	
	RebateIterator RebateManager::rebate_begin()
	{
		return m_rebates.begin();
	}
	
	RebateIterator RebateManager::rebate_end()
	{
		return m_rebates.end();
	}
	
	RebateConstIterator RebateManager::rebate_cbegin() const
	{
		return m_rebates.cbegin();
	}
	
	RebateConstIterator RebateManager::rebate_cend() const
	{
		return m_rebates.cend();
	}
}