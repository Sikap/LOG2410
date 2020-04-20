///////////////////////////////////////////////////////////
//  FixedRebate.cpp
//  Implementation of the Class FixedRebate
//  Created on:      10-mars-2020 16:01:16
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FixedRebate.h"

namespace PolyCharge
{
	FixedRebate::FixedRebate(const std::string& name, AbsSubscriptionPlan& plan, float percent)
		: AbsRebateDecorator(name, plan), m_percent(percent)
	{

	}
	
	void FixedRebate::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processFixedRebate(*this);
	}
	
	Amount FixedRebate::computeCost(kWh charge) const {
		Amount energyCost = m_plan.computeCost(charge) - m_plan.getSubscriptionCost();
		Amount reducedCost = energyCost*(1.0f-m_percent) + m_plan.getSubscriptionCost();
		return  reducedCost;
	}
	
	Amount FixedRebate::computeMarginalCost(kWh purchasedEnergy, kWh extraEnergy) const {
		return (purchasedEnergy > 0) ? m_plan.computeCost(extraEnergy)*(1.0f - m_percent) : computeCost(extraEnergy);
	}

	float FixedRebate::getRebatePercent() const
	{
		return m_percent;
	}
	void FixedRebate::setRebatePercent(float percent)
	{
		m_percent = percent >= 0 ? percent : 0.0f;
	}
}