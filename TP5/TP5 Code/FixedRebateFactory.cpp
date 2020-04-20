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
	const std::string FixedRebateFactory::m_name("FixedRebate");
	FixedRebateFactory FixedRebateFactory::m_instance;

	AbsRebateDecorator * FixedRebateFactory::createRebate(AbsSubscriptionPlan & plan, float percentRebate)
	{
		return new FixedRebate(m_name, plan, percentRebate);
	}

	FixedRebateFactory::FixedRebateFactory()
	{
		registerFactory(m_name, this);
	}
}
