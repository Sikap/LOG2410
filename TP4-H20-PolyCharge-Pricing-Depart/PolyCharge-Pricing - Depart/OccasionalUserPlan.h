///////////////////////////////////////////////////////////
//  OccasionalUser.h
//  Implementation of the Class OccasionalUser
//  Created on:      03-mars-2020 16:39:56
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_4EFD85AF_4D56_4c7c_AF30_CF6C7217293B__INCLUDED_)
#define EA_4EFD85AF_4D56_4c7c_AF30_CF6C7217293B__INCLUDED_

#include "AbsSubscriptionPlan.h"
#include "AbsSubscriptionPlanVisitor.h"

namespace PolyCharge
{
	class OccasionalUserPlan : public AbsSubscriptionPlan
	{

	public:
		OccasionalUserPlan() = default;
		virtual ~OccasionalUserPlan() = default;

		virtual void accept(AbsSubscriptionPlanVisitor& vis);
		virtual Amount computeCost(kWh charge) const;
		virtual Amount computeMarginalCost(kWh purchasedEnery, kWh extraEnergy) const;
		virtual Amount getSubscriptionCost() const;

	private:
		const float m_subscriptionCost = {20.0f};
		const float m_energyCost = {0.2f};
	};
}
#endif // !defined(EA_4EFD85AF_4D56_4c7c_AF30_CF6C7217293B__INCLUDED_)


