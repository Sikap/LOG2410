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

	AbsSubscriptionPlan* RegularPlanFactory::createPlan() const {
		return new RegularUserPlan();
	}
}
