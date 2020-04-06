///////////////////////////////////////////////////////////
//  AbsRebateFactory.h
//  Implementation of the Class AbsRebateFactory
//  Created on:      10-mars-2020 16:35:26
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_E46191C2_081E_48bc_8913_EECD0E8A5026__INCLUDED_)
#define EA_E46191C2_081E_48bc_8913_EECD0E8A5026__INCLUDED_

namespace PolyCharge
{
	class AbsRebateFactory
	{

	public:
		AbsRebateFactory() = default;
		virtual ~AbsRebateFactory() = default;

		virtual class AbsRebateDecorator* createRebate(class AbsSubscriptionPlan& plan) = 0;

	};
}
#endif // !defined(EA_E46191C2_081E_48bc_8913_EECD0E8A5026__INCLUDED_)
