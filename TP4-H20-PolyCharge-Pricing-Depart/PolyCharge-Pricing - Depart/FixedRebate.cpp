///////////////////////////////////////////////////////////
//  FixedRebate.cpp
//  Implementation of the Class FixedRebate
//  Created on:      10-mars-2020 16:01:16
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FixedRebate.h"

namespace PolyCharge
{
	FixedRebate::FixedRebate(AbsSubscriptionPlan& plan, float percent)
		: AbsRebateDecorator(plan), m_percent(percent)
	{

	}
	
	void FixedRebate::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processFixedRebate(*this);
	}
	
	Amount FixedRebate::computeCost(kWh charge) const {
		// Compute total energy cost including subscription fees and apply rebate to energy only
		Amount cost = m_plan.computeCost(charge); // To be completed
		cost -= getSubscriptionCost();
		cost *= 1 - getRebatePercent();
		cost += getSubscriptionCost();
		return cost;
	
	}
	
	Amount FixedRebate::computeMarginalCost(kWh purchasedEnergy, kWh extraEnergy) const {
		// Compute marginal energy cost, including subscription fees only if no previous purchase was made, and apply rebate to energy only
		kWh rebateCoef = 1 - getRebatePercent();
		return m_plan.computeMarginalCost(purchasedEnergy , extraEnergy) * rebateCoef; // To be completed
	}

	float FixedRebate::getRebatePercent() const
	{
		// To be completed
		return m_percent;
	}
	void FixedRebate::setRebatePercent(float percent)
	{
		// To be completed
		m_percent = percent;
	}
}