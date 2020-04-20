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
		virtual class AbsRebateDecorator* createRebate(class AbsSubscriptionPlan& plan, float percentRebate);

	protected:
		FixedRebateFactory();
		virtual ~FixedRebateFactory() = default;

		static const std::string m_name;
		static FixedRebateFactory m_instance;
	};
}
#endif // !defined(EA_905F4391_0BC0_4839_834F_C92F78EC34E2__INCLUDED_)
