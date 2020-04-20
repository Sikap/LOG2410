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
		virtual class AbsRebateDecorator* createRebate(class AbsSubscriptionPlan& plan, float percentRebate = 0.05f);

	protected:
		VariableRebateFactory();
		virtual ~VariableRebateFactory() = default;

		static const std::string m_name;
		static VariableRebateFactory m_instance;
	};
}
#endif // !defined(EA_7B01B030_7B1E_4685_92A9_93AF5435C5FF__INCLUDED_)
