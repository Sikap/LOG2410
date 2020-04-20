///////////////////////////////////////////////////////////
//  OccasionalUser.cpp
//  Implementation of the Class OccasionalUser
//  Created on:      03-mars-2020 16:39:56
//  Original author: francois
///////////////////////////////////////////////////////////

#include "OccasionalUserPlan.h"

namespace PolyCharge
{
	OccasionalUserPlan::OccasionalUserPlan(const std::string & name)
		: AbsSubscriptionPlan(name)
	{
	}

	void OccasionalUserPlan::accept(AbsSubscriptionPlanVisitor& vis) {
		vis.processOccasionalPlan(*this);
	}

	Amount OccasionalUserPlan::computeCost(kWh charge) const {

		return  m_subscriptionCost + charge * m_energyCost;
	}

	Amount OccasionalUserPlan::computeMarginalCost(kWh purchasedEnery, kWh extrakWh) const {

		Amount cost = extrakWh * m_energyCost;
		if (purchasedEnery == 0.0)
			cost += m_subscriptionCost;

		return  cost;
	}
	Amount OccasionalUserPlan::getSubscriptionCost() const
	{
		return m_subscriptionCost;
	}
}
