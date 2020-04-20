///////////////////////////////////////////////////////////
//  PolyChargePricing.h
//  Implementation of the Class PolyChargePricing
//  Created on:      10-mars-2020 16:43:36
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_0E22E756_AE71_475d_9FBC_0BF76BF09F61__INCLUDED_)
#define EA_0E22E756_AE71_475d_9FBC_0BF76BF09F61__INCLUDED_

#include <string>

#include "IPolyChargePrice.h"
#include "IPolyChargePlan.h"
#include "IPolyChargeRebate.h"

namespace PolyCharge
{
	class PolyChargePricing : public IPolyChargePrice, public IPolyChargePlan, public IPolyChargeRebate
	{
	public:
		PolyChargePricing();
		virtual ~PolyChargePricing() = default;

		virtual Amount computeCost(class AbsSubscriptionPlan& plan, kWh qee) const;
		virtual Amount computeMarginalCost(class AbsSubscriptionPlan& plan, kWh purchased, kWh extra) const;
		virtual AbsSubscriptionPlan& findPlan( std::string planName);
		virtual AbsSubscriptionPlan& createRebatePlan( const std::string& planName, const std::string& rebateName, float percentRebate );

		virtual PlanIterator plan_begin();
		virtual PlanIterator plan_end();
		virtual PlanConstIterator plan_cbegin() const;
		virtual PlanConstIterator plan_cend() const;


		virtual RebateTypeIterator rebateType_begin();
		virtual RebateTypeIterator rebateType_end();
		virtual RebateTypeConstIterator rebateType_cbegin() const;
		virtual RebateTypeConstIterator rebateType_cend() const;

		virtual RebateIterator rebate_begin();
		virtual RebateIterator rebate_end();
		virtual RebateConstIterator rebate_cbegin() const;
		virtual RebateConstIterator rebate_cend() const;

	protected:
		virtual void initialize(void);
	};
}
#endif // !defined(EA_0E22E756_AE71_475d_9FBC_0BF76BF09F61__INCLUDED_)
