///////////////////////////////////////////////////////////
//  OccasionalPlanFactory.cpp
//  Implementation of the Class OccasionalPlanFactory
//  Created on:      10-mars-2020 16:35:35
//  Original author: francois
///////////////////////////////////////////////////////////

#include "OccasionalPlanFactory.h"
#include "OccasionalUserPlan.h"

namespace PolyCharge
{

	AbsSubscriptionPlan* OccasionalPlanFactory::createPlan() const {
		return  new OccasionalUserPlan();
	}
}
