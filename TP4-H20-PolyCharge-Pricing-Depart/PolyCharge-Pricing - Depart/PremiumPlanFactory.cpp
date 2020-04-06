///////////////////////////////////////////////////////////
//  PremiumPlanFactory.cpp
//  Implementation of the Class PremiumPlanFactory
//  Created on:      10-mars-2020 16:35:29
//  Original author: francois
///////////////////////////////////////////////////////////

#include "PremiumPlanFactory.h"
#include "PremiumUserPlan.h"

namespace PolyCharge
{

	AbsSubscriptionPlan* PremiumPlanFactory::createPlan() const {
		return  new PremiumUserPlan();
	}
}
