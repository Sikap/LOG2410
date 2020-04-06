///////////////////////////////////////////////////////////
//  PlanManager.cpp
//  Implementation of the Class PlanManager
//  Created on:      08-mars-2020 16:18:47
//  Original author: francois
///////////////////////////////////////////////////////////

#include "PlanManager.h"

namespace PolyCharge
{
	void PlanManager::addPlanFactory(std::string factoryName, AbsPlanFactory* factoryp)
	{
		//m_planFactorys[factoryName] = std::make_unique<AbsPlanFactory>(factoryp);
		m_planFactorys[factoryName] = std::unique_ptr<AbsPlanFactory>(factoryp);
	}

	void PlanManager::addRebateFactory(std::string factoryName, AbsRebateFactory* factoryp)
	{
		//m_rebateFactorys[factoryName] = std::make_unique<AbsRebateFactory>(factoryp);
		m_rebateFactorys[factoryName] = std::unique_ptr<AbsRebateFactory>(factoryp);
	}

	AbsSubscriptionPlan& PlanManager::createPlan(std::string planName)
	{
		auto factoryPtr = m_planFactorys.find(planName);
		if (factoryPtr == m_planFactorys.end())
			throw std::range_error("No factory registered for the provided plan name");

		auto newPlan = factoryPtr->second.get()->createPlan();
		if(newPlan == nullptr)
			throw std::logic_error("Unable to create plan with registered factory");
		
		m_plans.push_back(std::unique_ptr<AbsSubscriptionPlan>(newPlan));

		return *newPlan;
	}
	AbsSubscriptionPlan & PlanManager::createRebatePlan(std::string planName, std::string rebateName)
	{
		auto& newPlan(createPlan(planName));

		auto rebateFactoryPtr = m_rebateFactorys.find(rebateName);
		if (rebateFactoryPtr == m_rebateFactorys.end())
			throw std::range_error("No factory registered for the provided rebate name");

		auto newRebate = rebateFactoryPtr->second.get()->createRebate(newPlan);
		if (newRebate == nullptr)
			throw std::logic_error("Unable to create rebate with registered factory");

		m_plans.push_back(std::unique_ptr<AbsSubscriptionPlan>(newRebate));

		return *newRebate;
	}
	PlanIterator PlanManager::begin()
	{
		return m_plans.begin();
	}
	PlanIterator PlanManager::end()
	{
		return m_plans.end();
	}
	PlanConstIterator PlanManager::cbegin() const
	{
		return m_plans.cbegin();
	}
	PlanConstIterator PlanManager::cend() const
	{
		return m_plans.cend();
	}
}
