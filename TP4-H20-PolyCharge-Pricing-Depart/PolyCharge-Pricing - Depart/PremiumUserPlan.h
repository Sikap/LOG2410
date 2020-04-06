///////////////////////////////////////////////////////////
//  PremiumUser.h
//  Implementation of the Class PremiumUser
//  Created on:      03-mars-2020 16:39:58
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_0FD7370B_C6ED_4484_9AF7_269E99628D7F__INCLUDED_)
#define EA_0FD7370B_C6ED_4484_9AF7_269E99628D7F__INCLUDED_

#include <utility>

#include "AbsSubscriptionPlan.h"
#include "AbsSubscriptionPlanVisitor.h"

namespace PolyCharge
{
	class PremiumUserPlan : public AbsSubscriptionPlan
	{

	public:
		PremiumUserPlan() = default;
		virtual ~PremiumUserPlan() = default;

		virtual void accept(AbsSubscriptionPlanVisitor& vis);
		virtual Amount computeCost(kWh charge) const;
		virtual Amount computeMarginalCost(kWh purchasedEnery, kWh extraEnergy) const;
		virtual Amount getSubscriptionCost() const;

	private:
		virtual Amount computeCostByLevels(kWh charge) const;

		const float m_subscriptionCost = { 40.0f };
		const std::pair<float, float> m_energyLevels[3] = { {100.0f, 0.1f}, {200.0f, 0.08f}, {0.0f, 0.07f} };
		const int m_nbLevels = 3;
	};
}
#endif // !defined(EA_0FD7370B_C6ED_4484_9AF7_269E99628D7F__INCLUDED_)
