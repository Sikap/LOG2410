///////////////////////////////////////////////////////////
//  FixedRebateFactory.cpp
//  Implementation of the Class FixedRebateFactory
//  Created on:      10-mars-2020 16:35:38
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FixedRebateFactory.h"
#include "FixedRebate.h"

namespace PolyCharge
{
	AbsRebateDecorator * FixedRebateFactory::createRebate(AbsSubscriptionPlan & plan)
	{
		return new FixedRebate(plan);
	}
}
