///////////////////////////////////////////////////////////
//  PremiumUser.cpp
//  Implementation of the Class PremiumUser
//  Created on:      03-mars-2020 16:39:58
//  Original author: francois
///////////////////////////////////////////////////////////

#include "PremiumUserPlan.h"

namespace PolyCharge
{

	void PremiumUserPlan::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processPremiumPlan(*this);
	}


	Amount PremiumUserPlan::computeCost(kWh charge) const {
		Amount cost = m_subscriptionCost;
		cost += computeCostByLevels(charge);
		return  cost;
	}

	Amount PremiumUserPlan::computeMarginalCost(kWh purchasedEnergy, kWh extrakWh) const {

		Amount cost = computeCostByLevels(purchasedEnergy + extrakWh);
		if (purchasedEnergy > 0)
			cost -= computeCost(purchasedEnergy);
		else
			cost += m_subscriptionCost;
		return  cost;
	}

	Amount PremiumUserPlan::getSubscriptionCost() const
	{
		return m_subscriptionCost;
	}

	Amount PremiumUserPlan::computeCostByLevels(kWh reste) const
	{
		Amount cost = 0.0f;
		int level = 0;
		while ((reste > m_energyLevels[level].first) && level < (m_nbLevels - 1))
		{
			cost += m_energyLevels[level].first * m_energyLevels[level].second;
			reste -= m_energyLevels[level].first;
			++level;
		}

		if (reste > 0.0)
			cost += reste * m_energyLevels[level].second;

		return cost;
	}
}
