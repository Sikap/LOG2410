///////////////////////////////////////////////////////////
//  OccasionalPlanFactory.cpp
//  Implementation of the Class OccasionalPlanFactory
//  Created on:      10-mars-2020 16:35:35
//  Original author: francois
///////////////////////////////////////////////////////////

#include "OccasionalPlanFactory.h"
#include "OccasionalUserPlan.h"
#include "PlanManager.h"

namespace PolyCharge
{
	const std::string OccasionalPlanFactory::m_name = "OccasionalUser";
	OccasionalPlanFactory OccasionalPlanFactory::m_instance;

	OccasionalPlanFactory::OccasionalPlanFactory()
	{
		registerFactory(m_name, this);
	}

	AbsSubscriptionPlan* OccasionalPlanFactory::createPlan() const {
		return  new OccasionalUserPlan( m_name );
	}
}
