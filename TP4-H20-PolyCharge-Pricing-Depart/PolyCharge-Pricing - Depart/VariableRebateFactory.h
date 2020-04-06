///////////////////////////////////////////////////////////
//  VariableRebateFactory.h
//  Implementation of the Class VariableRebateFactory
//  Created on:      10-mars-2020 16:35:40
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_7B01B030_7B1E_4685_92A9_93AF5435C5FF__INCLUDED_)
#define EA_7B01B030_7B1E_4685_92A9_93AF5435C5FF__INCLUDED_

#include "AbsRebateFactory.h"

namespace PolyCharge
{
	class VariableRebateFactory : public AbsRebateFactory
	{

	public:
		VariableRebateFactory() = default;
		virtual ~VariableRebateFactory() = default;

		virtual class AbsRebateDecorator* createRebate(class AbsSubscriptionPlan& plan);

	};
}
#endif // !defined(EA_7B01B030_7B1E_4685_92A9_93AF5435C5FF__INCLUDED_)
