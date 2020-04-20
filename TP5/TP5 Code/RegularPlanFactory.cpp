///////////////////////////////////////////////////////////
//  RegularPlanFactory.cpp
//  Implementation of the Class RegularPlanFactory
//  Created on:      10-mars-2020 16:35:32
//  Original author: francois
///////////////////////////////////////////////////////////

#include "RegularPlanFactory.h"
#include "RegularUserPlan.h"

namespace PolyCharge
{
	const std::string RegularPlanFactory::m_name = "RegularUser";
	RegularPlanFactory m_instance;

	RegularPlanFactory::RegularPlanFactory()
	{
		registerFactory(m_name, this);
	}

	AbsSubscriptionPlan* RegularPlanFactory::createPlan() const {
		return new RegularUserPlan( m_name );
	}
}
