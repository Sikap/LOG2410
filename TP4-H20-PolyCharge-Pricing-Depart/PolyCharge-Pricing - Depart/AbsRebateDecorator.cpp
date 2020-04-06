///////////////////////////////////////////////////////////
//  AbsRebateDecorator.cpp
//  Implementation of the Class AbsRebateDecorator
//  Created on:      10-mars-2020 16:01:12
//  Original author: francois
///////////////////////////////////////////////////////////

#include "AbsRebateDecorator.h"

namespace PolyCharge
{
	AbsRebateDecorator::AbsRebateDecorator(AbsSubscriptionPlan& plan)
		: m_plan(plan)
	{
	}


	Amount AbsRebateDecorator::getSubscriptionCost() const
	{
		return m_plan.getSubscriptionCost();
	}

	AbsSubscriptionPlan& AbsRebateDecorator::getPlan() {

		return  m_plan;
	}


	const AbsSubscriptionPlan& AbsRebateDecorator::getPlan() const {

		return  m_plan;
	}
}