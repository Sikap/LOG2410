///////////////////////////////////////////////////////////
//  TP5Tests.cpp
//  Implementation of the Class TP4Tests
//  Created on:      08-mars-2020 17:17:37
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "TP5Tests.h"
#include "AbsSubscriptionPlan.h"
#include "PlanManager.h"
#include "PremiumPlanFactory.h"
#include "PremiumUserPlan.h"
#include "RebateManager.h"

namespace PolyCharge
{
	void TP5Tests::testFactory()
	{
		std::cerr << std::boolalpha;
	}

	void TP5Tests::testSingleton()
	{
	}

	void TP5Tests::testMediator()
	{
		
		bool testSuccess = true;

		auto p = PremiumPlanFactory::PremiumPlanFactory();

		// On teste l'ajout du plan dans le conteneur m_plans
		PlanManager::getInstance().addPlanFactory("TestMediator", &p);
		PlanManager::getInstance().createAllPlans();
		try {
			m_pricing.findPlan("TestMediator");
		}
		catch (std::exception e) {
			testSuccess &= false;
		}


		std::cerr << "Test du patron Mediator : " << testSuccess << std::endl;
	}

	void TP5Tests::testFacade()
	{
		// On crée un décorateur FixedRebate d'utilisateur premium
		AbsSubscriptionPlan* fixedRebate = &m_pricing.createRebatePlan("PremiumUser", "FixedRebate", 0.50f);


		// On vérifie si le résultat est le même que celui dans le TP4
		bool testSuccess = m_pricing.computeCost(*fixedRebate, 30) == 42.85f;

		std::cerr <<  "Test du patron Facade : " << testSuccess << std::endl;

	}
}