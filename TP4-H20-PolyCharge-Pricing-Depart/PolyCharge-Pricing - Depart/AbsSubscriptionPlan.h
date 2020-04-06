///////////////////////////////////////////////////////////
//  AbsSubscriptionPlan.h
//  Implementation of the Class AbsSubscriptionPlan
//  Created on:      03-mars-2020 16:39:52
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_D36F5A92_B8A4_4404_990C_755D21C406CE__INCLUDED_)
#define EA_D36F5A92_B8A4_4404_990C_755D21C406CE__INCLUDED_

#include "PolyCharge.h"

namespace PolyCharge
{
	class AbsSubscriptionPlan
	{

	public:
		AbsSubscriptionPlan() = default;
		virtual ~AbsSubscriptionPlan() = default;

		virtual void accept(class AbsSubscriptionPlanVisitor& vis) = 0;
		virtual Amount computeCost(kWh charge) const = 0;
		virtual Amount computeMarginalCost(kWh purchasedEnery, kWh extraEnergy) const = 0;
		virtual Amount getSubscriptionCost() const = 0;
	};
}

#endif // !defined(EA_D36F5A92_B8A4_4404_990C_755D21C406CE__INCLUDED_)
