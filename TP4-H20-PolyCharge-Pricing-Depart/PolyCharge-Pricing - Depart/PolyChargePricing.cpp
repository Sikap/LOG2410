///////////////////////////////////////////////////////////
//  PolyChargePricing.cpp
//  Implementation of the Class PolyChargePricing
//  Created on:      10-mars-2020 16:43:36
//  Original author: francois
///////////////////////////////////////////////////////////

#include "PolyChargePricing.h"
#include "AbsSubscriptionPlan.h"
#include "PlanManager.h"

namespace PolyCharge
{
	Amount PolyChargePricing::computeCost(AbsSubscriptionPlan& plan, kWh qee) const
	{
		return plan.computeCost(qee);
	}
	Amount PolyChargePricing::computeMarginalCost(AbsSubscriptionPlan& plan, kWh purchased, kWh extra) const
	{
		return plan.computeMarginalCost(purchased, extra);
	}
	AbsSubscriptionPlan& PolyChargePricing::createPlan(PlanManager& planMngr, std::string planName)
	{
		return planMngr.createPlan(planName);
	}
	AbsSubscriptionPlan& PolyChargePricing::createRebatePlan(PlanManager& planMngr, std::string planName, std::string rebateName)
	{
		return planMngr.createRebatePlan(planName, rebateName);
	}
}
