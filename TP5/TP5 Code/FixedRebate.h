///////////////////////////////////////////////////////////
//  FixedRebate.h
//  Implementation of the Class FixedRebate
//  Created on:      10-mars-2020 16:01:16
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_01DED267_A8F2_4cbe_87DE_6ABB16A65A69__INCLUDED_)
#define EA_01DED267_A8F2_4cbe_87DE_6ABB16A65A69__INCLUDED_

#include "AbsRebateDecorator.h"
#include "AbsSubscriptionPlanVisitor.h"

namespace PolyCharge
{
	class FixedRebate : public AbsRebateDecorator
	{

	public:
		FixedRebate(const std::string& name, AbsSubscriptionPlan& plan, float percent = 0.05f);
		virtual ~FixedRebate() = default;

		virtual void accept(AbsSubscriptionPlanVisitor& vis);
		virtual Amount computeCost(kWh charge) const;
		virtual Amount computeMarginalCost(kWh purchasedEnery, kWh extraEnergy) const;
		virtual float getRebatePercent() const;
		virtual void setRebatePercent(float percent);

	protected:
		float m_percent;
	};
}
#endif // !defined(EA_01DED267_A8F2_4cbe_87DE_6ABB16A65A69__INCLUDED_)
