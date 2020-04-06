///////////////////////////////////////////////////////////
//  RegularUser.h
//  Implementation of the Class RegularUser
//  Created on:      03-mars-2020 16:39:54
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_64FDB20B_2E8D_41d5_B98D_C8EF41134C7D__INCLUDED_)
#define EA_64FDB20B_2E8D_41d5_B98D_C8EF41134C7D__INCLUDED_

#include "AbsSubscriptionPlan.h"
#include "AbsSubscriptionPlanVisitor.h"

namespace PolyCharge
{
	class RegularUserPlan : public AbsSubscriptionPlan
	{

	public:
		RegularUserPlan() = default;
		virtual ~RegularUserPlan() = default;

		virtual void accept(AbsSubscriptionPlanVisitor& vis);
		virtual Amount computeCost(kWh charge) const;
		virtual Amount computeMarginalCost(kWh purchasedEnery, kWh extraEnergy) const;
		virtual Amount getSubscriptionCost() const;

	private:
		const float m_subscriptionCost = { 30.0f };
		const float m_energyCost = { 0.12f };
	};
}
#endif // !defined(EA_64FDB20B_2E8D_41d5_B98D_C8EF41134C7D__INCLUDED_)