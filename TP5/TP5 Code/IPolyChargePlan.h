///////////////////////////////////////////////////////////
//  IPolyChargePlan.h
//  Implementation of the Interface IPolyChargePlan
//  Created on:      03-avr.-2020 14:19:16
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_32996074_2DA0_485f_9983_A647FFFBD016__INCLUDED_)
#define EA_32996074_2DA0_485f_9983_A647FFFBD016__INCLUDED_

#include <string>

#include "PolyCharge.h"

namespace PolyCharge
{
	class AbsSubscriptionPlan;

	using PlanPointer = std::unique_ptr<AbsSubscriptionPlan>;
	using PlanContainer = std::unordered_map<std::string, PlanPointer>;
	using PlanIterator = PlanContainer::iterator;
	using PlanConstIterator = PlanContainer::const_iterator;

	class IPolyChargePlan
	{
		virtual class AbsSubscriptionPlan& findPlan(std::string planName) = 0;

		virtual PlanIterator plan_begin() = 0;
		virtual PlanIterator plan_end() = 0;
		virtual PlanConstIterator plan_cbegin() const = 0;
		virtual PlanConstIterator plan_cend() const = 0;
	};
}
#endif // !defined(EA_32996074_2DA0_485f_9983_A647FFFBD016__INCLUDED_)
