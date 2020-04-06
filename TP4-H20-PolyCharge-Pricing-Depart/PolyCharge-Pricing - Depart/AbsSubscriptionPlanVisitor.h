///////////////////////////////////////////////////////////
//  AbsSubscriptionPlanVisitor.h
//  Implementation of the Class AbsSubscriptionPlanVisitor
//  Created on:      10-mars-2020 16:01:01
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_25B795DE_52BC_4c36_8230_433A4FF6E2B2__INCLUDED_)
#define EA_25B795DE_52BC_4c36_8230_433A4FF6E2B2__INCLUDED_

namespace PolyCharge
{
	class AbsSubscriptionPlanVisitor
	{

	public:
		AbsSubscriptionPlanVisitor() = default;
		virtual ~AbsSubscriptionPlanVisitor() = default;

		virtual void processFixedRebate(class FixedRebate& rebate) = 0;
		virtual void processOccasionalPlan(class OccasionalUserPlan& plan) = 0;
		virtual void processPremiumPlan(class PremiumUserPlan& plan) = 0;
		virtual void processRegularPlan(class RegularUserPlan& plan) = 0;
		virtual void processVariableRebate(class VariableRebate& rebate) = 0;
	};
}
#endif // !defined(EA_25B795DE_52BC_4c36_8230_433A4FF6E2B2__INCLUDED_)
