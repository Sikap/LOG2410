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
#include "RegularPlanFactory.h"
#include "PremiumUserPlan.h"
#include "RebateManager.h"
#include "FixedRebateFactory.h"

namespace PolyCharge
{
	void TP5Tests::testFactory()
	{
		std::cerr << std::boolalpha;

		// On v�rifie le type de l'objet cr�� par le patron Factory
		AbsPlanFactory* planFactory = new PremiumPlanFactory();
		auto p = planFactory->createPlan();
		bool testSuccess = p->name() == "PremiumUser";

		std::cerr << "Test du patron Factory : " << testSuccess << std::endl;

	}

	void TP5Tests::testSingleton()
	{

		bool testSuccess = false;
		
		// On v�rifie si la double instanciation �quivaut � une simple instanciation
		auto s = &PlanManager::getInstance();
		auto p = &(s->getInstance());

		if (p == s) {
			testSuccess |= true;
		}

		std::cerr << "Test du patron Singleton : " << testSuccess << std::endl;
			

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
		// On cr�e un d�corateur FixedRebate d'utilisateur premium
		AbsSubscriptionPlan* fixedRebate = &m_pricing.createRebatePlan("PremiumUser", "FixedRebate", 0.50f);


		// On v�rifie si le r�sultat est le m�me que celui dans le TP4
		bool testSuccess = m_pricing.computeCost(*fixedRebate, 30) == 42.85f;

		std::cerr <<  "Test du patron Facade : " << testSuccess << std::endl;

	}
}