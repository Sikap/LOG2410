///////////////////////////////////////////////////////////
//  TP4Tests.cpp
//  Implementation of the Class TP4Tests
//  Created on:      08-mars-2020 17:17:37
//  Original author: francois
///////////////////////////////////////////////////////////

#include <iostream>

#include "TP4Tests.h"

#include "OccasionalPlanFactory.h"
#include "RegularPlanFactory.h"
#include "PremiumPlanFactory.h"

#include "FixedRebateFactory.h"
#include "VariableRebateFactory.h"

#include "OccasionalUserPlan.h"
#include "RegularUserPlan.h"
#include "PremiumUserPlan.h"

#include "FixedRebate.h"
#include "VariableRebate.h"

namespace PolyCharge
{

	TP4Tests::TP4Tests()
	{
		// Initialize to true for more tests
		m_extendedTests = false;

		// Initialize plan creation factories
		m_planMngr.addPlanFactory("OccasionalPlan", new PolyCharge::OccasionalPlanFactory());
		m_planMngr.addPlanFactory("RegularPlan", new PolyCharge::RegularPlanFactory());
		m_planMngr.addPlanFactory("PremiumPlan", new PolyCharge::PremiumPlanFactory());

		// Initialiser rebate creation factories
		m_planMngr.addRebateFactory("FixedRebate", new PolyCharge::FixedRebateFactory());
		m_planMngr.addRebateFactory("VariableRebate", new PolyCharge::VariableRebateFactory());
	}


	void TP4Tests::testDecorator() {
		std::cout << "TP4 --- Execution of DECORATOR tests\n";

		// Initialize 3 plans using plan factories
		AbsSubscriptionPlan& o_plan = m_planMngr.createPlan("OccasionalPlan");
		AbsSubscriptionPlan& r_plan = m_planMngr.createPlan("RegularPlan");
		AbsSubscriptionPlan& p_plan = m_planMngr.createPlan("PremiumPlan");

		if (m_extendedTests)
		{
			// Compute marginal cost of 0kWh recharge after 0kWh purchase for each plan
			// This gives the subscription rate
			float marge_cost0kWh_o = o_plan.computeMarginalCost(0,0);
			float marge_cost0kWh_r = r_plan.computeMarginalCost(0,0);
			float marge_cost0kWh_p = p_plan.computeMarginalCost(0,0);

			std::cout << "Marginal cost of 0kWh after 0kWh purchase for occasional plan: " << marge_cost0kWh_o << std::endl;
			std::cout << "Marginal cost of 0kWh after 0kWh purchase for regular plan: " << marge_cost0kWh_r << std::endl;
			std::cout << "Marginal cost of 0kWh after 0kWh purchase for premium plan: " << marge_cost0kWh_p << std::endl << std::endl;

			// Compute cost of 30kWh recharge for each plan
			float cost30kWh_o = o_plan.computeCost(30);
			float cost30kWh_r = r_plan.computeCost(30);
			float cost30kWh_p = p_plan.computeCost(30);

			std::cout << "Cost of 30kWh for occasional plan: " << cost30kWh_o << std::endl;
			std::cout << "Cost of 30kWh for regular plan: " << cost30kWh_r << std::endl;
			std::cout << "Cost of 30kWh for premium plan: " << cost30kWh_p << std::endl << std::endl;

			// Compute cost of 150kWh recharge for each plan
			float cost150kWh_o = o_plan.computeCost(150);
			float cost150kWh_r = r_plan.computeCost(150);
			float cost150kWh_p = p_plan.computeCost(150);

			std::cout << "Cost of 150kWh for occasional plan: " << cost150kWh_o << std::endl;
			std::cout << "Cost of 150kWh for regular plan: " << cost150kWh_r << std::endl;
			std::cout << "Cost of 150kWh for premium plan: " << cost150kWh_p << std::endl << std::endl;

			// Compute cost of 250kWh recharge for each plan
			float cost250kWh_o = o_plan.computeCost(250);
			float cost250kWh_r = r_plan.computeCost(250);
			float cost250kWh_p = p_plan.computeCost(250);

			std::cout << "Cost of 250kWh for occasional plan: " << cost250kWh_o << std::endl;
			std::cout << "Cost of 250kWh for regular plan: " << cost250kWh_r << std::endl;
			std::cout << "Cost of 250kWh for premium plan: " << cost250kWh_p << std::endl << std::endl;

			// Compute cost of 350kWh recharge for each plan
			float cost350kWh_o = o_plan.computeCost(350);
			float cost350kWh_r = r_plan.computeCost(350);
			float cost350kWh_p = p_plan.computeCost(350);

			std::cout << "Cost of 350kWh for occasional plan: " << cost350kWh_o << std::endl;
			std::cout << "Cost of 350kWh for regular plan: " << cost350kWh_r << std::endl;
			std::cout << "Cost of 350kWh for premium plan: " << cost350kWh_p << std::endl << std::endl;
		}

		// Initialize 3 plans with fixed rebate using rebate factories
		AbsSubscriptionPlan& o_rebate = m_planMngr.createRebatePlan("OccasionalPlan", "FixedRebate");
		AbsSubscriptionPlan& r_rebate = m_planMngr.createRebatePlan("RegularPlan", "FixedRebate");
		AbsSubscriptionPlan& p_rebate = m_planMngr.createRebatePlan("PremiumPlan", "FixedRebate");

		// Compute cost of 30kWh recharge for each plan with variable rebate
		float cost30kWh_o_rebate5 = o_rebate.computeCost(30);
		float cost30kWh_r_rebate5 = r_rebate.computeCost(30);
		float cost30kWh_p_rebate5 = p_rebate.computeCost(30);

		std::cout << std::endl;
		std::cout << "Cost of 30kWh for occasional plan with variable rebate: " << cost30kWh_o_rebate5 << std::endl;
		std::cout << "Cost of 30kWh for regular plan with variable rebate: " << cost30kWh_r_rebate5 << std::endl;
		std::cout << "Cost of 30kWh for premium plan with variable rebate: " << cost30kWh_p_rebate5 << std::endl;

		std::cout << std::endl << "DECORATOR TEST 1 --- ";
		if (compareEqual( cost30kWh_o_rebate5, 25.7f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";

		std::cout << std::endl << "DECORATOR TEST 2 --- ";
		if (compareEqual(cost30kWh_r_rebate5, 33.42f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";

		std::cout << std::endl << "DECORATOR TEST 3 --- ";
		if (compareEqual(cost30kWh_p_rebate5, 42.85f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";
		std::cout << std::endl << std::endl;

		// Compute cost of 350kWh recharge for each plan with 5% rebate
		float cost350kWh_o_rebate5 = o_rebate.computeCost(350);
		float cost350kWh_r_rebate5 = r_rebate.computeCost(350);
		float cost350kWh_p_rebate5 = p_rebate.computeCost(350);

		std::cout << "Cost of 350kWh for occasional plan with 5% rebate: " << cost350kWh_o_rebate5 << std::endl;
		std::cout << "Cost of 350kWh for regular plan with 5% rebate: " << cost350kWh_r_rebate5 << std::endl;
		std::cout << "Cost of 350kWh for premium plan with 5% rebate: " << cost350kWh_p_rebate5 << std::endl;

		std::cout << std::endl << "DECORATOR TEST 4 --- ";
		if (compareEqual(cost350kWh_o_rebate5, 86.5f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";

		std::cout << std::endl << "DECORATOR TEST 5 --- ";
		if (compareEqual(cost350kWh_r_rebate5, 69.9f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED ";

		std::cout << std::endl << "DECORATOR TEST 6 --- ";
		if (compareEqual(cost350kWh_p_rebate5, 68.025f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";
		std::cout << std::endl << std::endl;
	}


	void TP4Tests::testVisitor() {
		std::cout << "TP4 --- Execution of VISITOR tests\n";

		// Initialize 3 plans with variable rebate using rebate factories
		AbsSubscriptionPlan& o_rebate = m_planMngr.createRebatePlan("OccasionalPlan", "VariableRebate");
		AbsSubscriptionPlan& r_rebate = m_planMngr.createRebatePlan("RegularPlan", "VariableRebate");
		AbsSubscriptionPlan& p_rebate = m_planMngr.createRebatePlan("PremiumPlan", "VariableRebate");

		// Compute cost of 30kWh recharge for each plan with 5% rebate
		float cost30kWh_o_rebateVar = o_rebate.computeCost(30);
		float cost30kWh_r_rebateVar = r_rebate.computeCost(30);
		float cost30kWh_p_rebateVar = p_rebate.computeCost(30);

		std::cout << std::endl;
		std::cout << "Cost of 30kWh for occasional plan with variable rebate: " << cost30kWh_o_rebateVar << std::endl;
		std::cout << "Cost of 30kWh for regular plan with variable rebate: " << cost30kWh_r_rebateVar << std::endl;
		std::cout << "Cost of 30kWh for premium plan with variable rebate: " << cost30kWh_p_rebateVar << std::endl;

		std::cout << std::endl << "VISITOR TEST 1 --- ";
		if (compareEqual(cost30kWh_o_rebateVar, 24.94f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";

		std::cout << std::endl << "VISITOR TEST 2 --- ";
		if (compareEqual(cost30kWh_r_rebateVar, 32.01f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";

		std::cout << std::endl << "VISITOR TEST 3 --- ";
		if (compareEqual(cost30kWh_p_rebateVar, 38.85f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";
		std::cout << std::endl << std::endl;

		// Compute cost of 350kWh recharge for each plan with variable rebate
		float cost350kWh_o_rebateVar = o_rebate.computeCost(350);
		float cost350kWh_r_rebateVar = r_rebate.computeCost(350);
		float cost350kWh_p_rebateVar = p_rebate.computeCost(350);

		std::cout << "Cost of 350kWh for occasional plan with variable rebate: " << cost350kWh_o_rebateVar << std::endl;
		std::cout << "Cost of 350kWh for regular plan with variable rebate: " << cost350kWh_r_rebateVar << std::endl;
		std::cout << "Cost of 350kWh for premium plan with variable rebate: " << cost350kWh_p_rebateVar << std::endl;

		std::cout << std::endl << "VISITOR TEST 4 --- ";
		if (compareEqual(cost350kWh_o_rebateVar, 88.3f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";

		std::cout << std::endl << "VISITOR TEST 5 --- ";
		if (compareEqual(cost350kWh_r_rebateVar, 69.45f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED ";

		std::cout << std::endl << "VISITOR TEST 6 --- ";
		if (compareEqual(cost350kWh_p_rebateVar, 64.025f))
			std::cout << "SUCCESS";
		else
			std::cout << "FAILED";
		std::cout << std::endl << std::endl;
	}

	bool TP4Tests::compareEqual(float a, float b)
	{
		return fabs(a - b) < 0.001f;
	}
}