///////////////////////////////////////////////////////////
//  VariableRebate.h
//  Implementation of the Class VariableRebate
//  Created on:      10-mars-2020 16:01:19
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_388D9902_539D_4646_937E_1807E629B86B__INCLUDED_)
#define EA_388D9902_539D_4646_937E_1807E629B86B__INCLUDED_

#include "AbsRebateDecorator.h"
#include "AbsSubscriptionPlanVisitor.h"

namespace PolyCharge
{
	class VariableRebate : public AbsRebateDecorator, public AbsSubscriptionPlanVisitor
	{

	public:
		VariableRebate(AbsSubscriptionPlan& plan, float percent = 0.05f);
		virtual ~VariableRebate() = default;

		virtual void accept(AbsSubscriptionPlanVisitor& vis);
		virtual Amount computeCost(kWh charge) const;
		virtual Amount computeMarginalCost(kWh purchasedEnergy, kWh extraEnergy) const;

		virtual void processFixedRebate(FixedRebate& rebate);
		virtual void processOccasionalPlan(OccasionalUserPlan& plan);
		virtual void processPremiumPlan(PremiumUserPlan& plan);
		virtual void processRegularPlan(RegularUserPlan& plan);
		virtual void processVariableRebate(VariableRebate& rebate);

		virtual float getRebatePercent() const;
		virtual void setRebatePercent(float percent);

	protected:
		float m_basePercent;
		float m_subscriptionRebate;
		float m_energyRebate;
	};
}
#endif // !defined(EA_388D9902_539D_4646_937E_1807E629B86B__INCLUDED_)
