///////////////////////////////////////////////////////////
//  PolyChargePricing.cpp
//  Implementation of the Class PolyChargePricing
//  Created on:      10-mars-2020 16:43:36
//  Original author: francois
///////////////////////////////////////////////////////////

#include "PolyChargePricing.h"
#include "AbsSubscriptionPlan.h"
#include "PlanManager.h"
#include "RebateManager.h"

namespace PolyCharge
{
	void PolyChargePricing::initialize(void)
	{
		// Initialize plans
		PlanManager::getInstance().createAllPlans();
	}

	PolyChargePricing::PolyChargePricing()
	{
		initialize();
	}

	Amount PolyChargePricing::computeCost(AbsSubscriptionPlan& plan, kWh qee) const
	{
		return plan.computeCost(qee);
	}

	Amount PolyChargePricing::computeMarginalCost(AbsSubscriptionPlan& plan, kWh purchased, kWh extra) const
	{
		return plan.computeMarginalCost(purchased, extra);
	}
	
	AbsSubscriptionPlan& PolyChargePricing::findPlan( std::string planName )
	{
		return PlanManager::getInstance().findPlan(planName);
	}
	
	AbsSubscriptionPlan & PolyChargePricing::createRebatePlan(const std::string& planName, const std::string& rebateName, float percentRebate)
	{
		AbsSubscriptionPlan& plan = PlanManager::getInstance().findPlan(planName);
		return RebateManager::getInstance().createRebate(rebateName, plan, percentRebate);
	}
	
	PlanIterator PolyChargePricing::plan_begin()
	{
		return PlanManager::getInstance().begin();
	}
	
	PlanIterator PolyChargePricing::plan_end()
	{
		return PlanManager::getInstance().end();
	}
	
	PlanConstIterator PolyChargePricing::plan_cbegin() const
	{
		return PlanManager::getInstance().cbegin();
	}
	
	PlanConstIterator PolyChargePricing::plan_cend() const
	{
		return PlanManager::getInstance().cend();
	}
	
	RebateTypeIterator PolyChargePricing::rebateType_begin()
	{
		return RebateManager::getInstance().rebateType_begin();
	}
	
	RebateTypeIterator PolyChargePricing::rebateType_end()
	{
		return RebateManager::getInstance().rebateType_end();
	}
	
	RebateTypeConstIterator PolyChargePricing::rebateType_cbegin() const
	{
		return RebateManager::getInstance().rebateType_cbegin();
	}
	
	RebateTypeConstIterator PolyChargePricing::rebateType_cend() const
	{
		return RebateManager::getInstance().rebateType_cend();
	}
	
	RebateIterator PolyChargePricing::rebate_begin()
	{
		return RebateManager::getInstance().rebate_begin();
	}
	
	RebateIterator PolyChargePricing::rebate_end()
	{
		return RebateManager::getInstance().rebate_end();
	}
	
	RebateConstIterator PolyChargePricing::rebate_cbegin() const
	{
		return RebateManager::getInstance().rebate_cbegin();
	}
	
	RebateConstIterator PolyChargePricing::rebate_cend() const
	{
		return RebateManager::getInstance().rebate_cend();
	}
}
