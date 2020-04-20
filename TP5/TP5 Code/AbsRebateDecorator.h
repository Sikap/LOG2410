///////////////////////////////////////////////////////////
//  AbsRebateDecorator.h
//  Implementation of the Class AbsRebateDecorator
//  Created on:      10-mars-2020 16:01:12
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_257A8AC9_02C9_43aa_803C_F8A6AD47D473__INCLUDED_)
#define EA_257A8AC9_02C9_43aa_803C_F8A6AD47D473__INCLUDED_

#include "AbsSubscriptionPlan.h"

namespace PolyCharge
{
	class AbsRebateDecorator : public AbsSubscriptionPlan
	{

	public:
		AbsRebateDecorator(const std::string& name, AbsSubscriptionPlan& plan);
		virtual ~AbsRebateDecorator() = default;

		virtual void accept(class AbsSubscriptionPlanVisitor& vis) = 0;
		virtual Amount computeCost(kWh charge) const = 0;
		virtual Amount computeMarginalCost(kWh purchasedEnery, kWh extraEnergy) const = 0;
		virtual Amount getSubscriptionCost() const;

		virtual AbsSubscriptionPlan& getPlan();
		virtual const AbsSubscriptionPlan& getPlan() const;
		virtual float getRebatePercent() const = 0;
		virtual void setRebatePercent(float percent) = 0;
	
	protected:
		AbsSubscriptionPlan& m_plan;
	};
}
#endif // !defined(EA_257A8AC9_02C9_43aa_803C_F8A6AD47D473__INCLUDED_)
