///////////////////////////////////////////////////////////
//  PlanManager.cpp
//  Implementation of the Class PlanManager
//  Created on:      08-mars-2020 16:18:47
//  Original author: francois
///////////////////////////////////////////////////////////

#include "PlanManager.h"

namespace PolyCharge
{
	PlanManager & PlanManager::getInstance(void)
	{
		static PlanManager instance;

		return instance;
	}

	void PlanManager::addPlanFactory(std::string factoryName, PlanFactoryPointer factoryp)
	{
		m_planFactorys[factoryName] = factoryp;
	}

	void PlanManager::createAllPlans(void)
	{
		for (auto factoryIter = m_planFactorys.begin(); factoryIter != m_planFactorys.end(); ++factoryIter)
		{
			auto newPlan = factoryIter->second->createPlan();
			if (newPlan == nullptr)
				throw std::logic_error("Unable to create plan with registered factory");

			m_plans[factoryIter->first] = std::unique_ptr<AbsSubscriptionPlan>(newPlan);
		}
	}

	AbsSubscriptionPlan & PlanManager::findPlan(const std::string & planName)
	{
		auto planIter = m_plans.find(planName);
		if (planIter == m_plans.end())
			throw(std::domain_error("No plan found for provided plan name"));
		else
			return *(planIter->second);
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
	PlanManager::~PlanManager()
	{
		m_plans.clear();
		m_planFactorys.clear();
	}
}
