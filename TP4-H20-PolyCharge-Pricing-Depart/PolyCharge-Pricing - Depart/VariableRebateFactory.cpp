///////////////////////////////////////////////////////////
//  VariableRebateFactory.cpp
//  Implementation of the Class VariableRebateFactory
//  Created on:      10-mars-2020 16:35:40
//  Original author: francois
///////////////////////////////////////////////////////////

#include "VariableRebateFactory.h"
#include "VariableRebate.h"

namespace PolyCharge
{
	AbsRebateDecorator * VariableRebateFactory::createRebate(AbsSubscriptionPlan & plan)
	{
		return new VariableRebate(plan);
	}
}
