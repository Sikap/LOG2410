///////////////////////////////////////////////////////////
//  PremiumPlanFactory.h
//  Implementation of the Class PremiumPlanFactory
//  Created on:      10-mars-2020 16:35:29
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_9AABB69B_E407_4980_8417_E6BB4DF272F7__INCLUDED_)
#define EA_9AABB69B_E407_4980_8417_E6BB4DF272F7__INCLUDED_

#include "AbsPlanFactory.h"

namespace PolyCharge
{
	class PremiumPlanFactory : public AbsPlanFactory
	{

	public:
		PremiumPlanFactory() = default;
		virtual ~PremiumPlanFactory() = default;

		virtual class AbsSubscriptionPlan* createPlan() const;

	};
}
#endif // !defined(EA_9AABB69B_E407_4980_8417_E6BB4DF272F7__INCLUDED_)
