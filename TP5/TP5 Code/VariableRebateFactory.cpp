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
	const std::string VariableRebateFactory::m_name("VariableRebate");
	VariableRebateFactory VariableRebateFactory::m_instance;

	VariableRebateFactory::VariableRebateFactory()
	{
		registerFactory(m_name, this);
	}

	AbsRebateDecorator * VariableRebateFactory::createRebate(AbsSubscriptionPlan & plan, float percentRebate)
	{
		return new VariableRebate(m_name, plan, percentRebate);
	}
}
