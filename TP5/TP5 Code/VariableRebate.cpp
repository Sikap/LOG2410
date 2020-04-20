///////////////////////////////////////////////////////////
//  VariableRebate.cpp
//  Implementation of the Class VariableRebate
//  Created on:      10-mars-2020 16:01:19
//  Original author: francois
///////////////////////////////////////////////////////////

#include "VariableRebate.h"
#include "FixedRebate.h"
#include "OccasionalUserPlan.h"
#include "RegularUserPlan.h"
#include "PremiumUserPlan.h"

namespace PolyCharge
{
	VariableRebate::VariableRebate(const std::string& name, AbsSubscriptionPlan& plan, float percent)
		: AbsRebateDecorator(name, plan), m_basePercent(percent) {

	}

	void VariableRebate::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processVariableRebate(*this);
	}

	Amount VariableRebate::computeCost(kWh charge) const {
		// Apply rebate as visitor to decorated plan to initialize appropriate percentages
		// To use the visitor, its constness must be removed with const_cast
		m_plan.accept(const_cast<VariableRebate&>(*this));

		// Apply distinct rebates to subscription and energy
		Amount subscriptionCost = m_plan.getSubscriptionCost();
		Amount energyCost = m_plan.computeCost(charge) - subscriptionCost;
		Amount rebateCost = subscriptionCost * (1.0f - m_subscriptionRebate) + energyCost * (1.0f - m_energyRebate);

		return  rebateCost;
	}

	Amount VariableRebate::computeMarginalCost(kWh purchasedEnergy, kWh extraEnergy) const {
		Amount rebateCost = 0.0;
		if (purchasedEnergy > 0.0f)
		{
			// Apply rebate as visitor to decorated plan to initialize appropriate percentages
			// To use the visitor, its constness must be removed with const_cast
			m_plan.accept(const_cast<VariableRebate&>(*this));

			// Apply distinct rebates to subscription and energy
			rebateCost = m_plan.computeMarginalCost(purchasedEnergy, extraEnergy) * (1.0f - m_energyRebate);
		}
		else
		{
			rebateCost = computeCost(extraEnergy);
		}

		return  rebateCost;
	}


	void VariableRebate::processFixedRebate(FixedRebate& rebate) {
		rebate.getPlan().accept(*this);
	}


	void VariableRebate::processOccasionalPlan(OccasionalUserPlan& plan) {
		// Initialize rebates according to OccasionalPlan
		m_subscriptionRebate = m_basePercent;
		m_energyRebate = m_basePercent * 0.2f;
	}


	void VariableRebate::processPremiumPlan(PremiumUserPlan& plan) {
		// Initialize rebates according to PremiumPlan
		m_subscriptionRebate = 2.0f*m_basePercent;
		m_energyRebate = m_basePercent;
	}


	void VariableRebate::processRegularPlan(RegularUserPlan& plan) {
		// Initialize rebates according to PremiumPlan
		m_subscriptionRebate = m_basePercent;
		m_energyRebate = 0.5f * m_basePercent;
	}


	void VariableRebate::processVariableRebate(VariableRebate& rebate) {
		rebate.getPlan().accept(*this);
	}

	float PolyCharge::VariableRebate::getRebatePercent() const
	{
		return m_basePercent;
	}

	void PolyCharge::VariableRebate::setRebatePercent(float percent)
	{
		m_basePercent = percent >= 0 ? percent : 0.0f;
	}
}