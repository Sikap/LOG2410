///////////////////////////////////////////////////////////
//  IPolyChargePrice.h
//  Implementation of the Interface IPolyChargePrice
//  Created on:      03-avr.-2020 14:18:59
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_19E52E3F_E994_4621_8483_6CC64BEFD40C__INCLUDED_)
#define EA_19E52E3F_E994_4621_8483_6CC64BEFD40C__INCLUDED_

#include "PolyCharge.h"

namespace PolyCharge
{
	class IPolyChargePrice
	{
		virtual Amount computeCost(class AbsSubscriptionPlan& plan, kWh qee) const = 0;
		virtual Amount computeMarginalCost(class AbsSubscriptionPlan& plan, kWh purchased, kWh extra) const = 0;
	};
}

#endif // !defined(EA_19E52E3F_E994_4621_8483_6CC64BEFD40C__INCLUDED_)
