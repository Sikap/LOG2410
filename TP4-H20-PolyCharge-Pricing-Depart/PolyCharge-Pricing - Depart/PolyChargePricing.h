///////////////////////////////////////////////////////////
//  PolyChargePricing.h
//  Implementation of the Class PolyChargePricing
//  Created on:      10-mars-2020 16:43:36
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_0E22E756_AE71_475d_9FBC_0BF76BF09F61__INCLUDED_)
#define EA_0E22E756_AE71_475d_9FBC_0BF76BF09F61__INCLUDED_

#include <string>
#include "PolyCharge.h"

namespace PolyCharge
{
	class IPolyChargePrice
	{
		virtual Amount computeCost(class AbsSubscriptionPlan& plan, kWh qee) const = 0;
		virtual Amount computeMarginalCost(class AbsSubscriptionPlan& plan, kWh purchased, kWh extra) const = 0;
	};

	class IPolyChargePlan
	{
		virtual AbsSubscriptionPlan& createPlan(class PlanManager& planMngr, std::string planName) = 0;
		virtual AbsSubscriptionPlan& createRebatePlan(class PlanManager& planMngr, std::string planName, std::string rebateName) = 0;
	};

	class PolyChargePricing : public IPolyChargePrice, public IPolyChargePlan
	{
		PolyChargePricing() = default;
		virtual ~PolyChargePricing() = default;

		virtual Amount computeCost(class AbsSubscriptionPlan& plan, kWh qee) const;
		virtual Amount computeMarginalCost(class AbsSubscriptionPlan& plan, kWh purchased, kWh extra) const;
		virtual AbsSubscriptionPlan& createPlan(class PlanManager& planMngr, std::string planName);
		virtual AbsSubscriptionPlan& createRebatePlan(class PlanManager& planMngr, std::string planName, std::string rebateName);
	};
}
#endif // !defined(EA_0E22E756_AE71_475d_9FBC_0BF76BF09F61__INCLUDED_)
