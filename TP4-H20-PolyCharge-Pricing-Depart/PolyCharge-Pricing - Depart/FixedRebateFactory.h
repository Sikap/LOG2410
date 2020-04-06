///////////////////////////////////////////////////////////
//  FixedRebateFactory.h
//  Implementation of the Class FixedRebateFactory
//  Created on:      10-mars-2020 16:35:38
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_905F4391_0BC0_4839_834F_C92F78EC34E2__INCLUDED_)
#define EA_905F4391_0BC0_4839_834F_C92F78EC34E2__INCLUDED_

#include "AbsRebateFactory.h"

namespace PolyCharge
{
	class FixedRebateFactory : public AbsRebateFactory
	{

	public:
		FixedRebateFactory() = default;
		virtual ~FixedRebateFactory() = default;

		virtual class AbsRebateDecorator* createRebate(class AbsSubscriptionPlan& plan);

	};
}
#endif // !defined(EA_905F4391_0BC0_4839_834F_C92F78EC34E2__INCLUDED_)
