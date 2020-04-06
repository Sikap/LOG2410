///////////////////////////////////////////////////////////
//  RegularUser.cpp
//  Implementation of the Class RegularUser
//  Created on:      03-mars-2020 16:39:54
//  Original author: francois
///////////////////////////////////////////////////////////

#include "RegularUserPlan.h"

namespace PolyCharge
{

	void RegularUserPlan::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processRegularPlan(*this);
	}

	Amount RegularUserPlan::computeCost(kWh charge) const {

		return  m_subscriptionCost + charge * m_energyCost;
	}

	Amount RegularUserPlan::computeMarginalCost(kWh purchasedEnery, kWh extrakWh) const {

		Amount cost = extrakWh * m_energyCost;
		if (purchasedEnery == 0.0)
			cost += m_subscriptionCost;

		return  cost;
	}
	Amount RegularUserPlan::getSubscriptionCost() const
	{
		return m_subscriptionCost;
	}
}
