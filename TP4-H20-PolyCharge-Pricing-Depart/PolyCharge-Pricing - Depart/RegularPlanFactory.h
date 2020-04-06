///////////////////////////////////////////////////////////
//  RegularPlanFactory.h
//  Implementation of the Class RegularPlanFactory
//  Created on:      10-mars-2020 16:35:32
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_F1E4C0AA_8A3D_4e28_BF8A_07083DD023B5__INCLUDED_)
#define EA_F1E4C0AA_8A3D_4e28_BF8A_07083DD023B5__INCLUDED_

#include "AbsPlanFactory.h"

namespace PolyCharge
{
	class RegularPlanFactory : public AbsPlanFactory
	{

	public:
		RegularPlanFactory() = default;
		virtual ~RegularPlanFactory() = default;

		virtual class AbsSubscriptionPlan* createPlan() const;

	};
}
#endif // !defined(EA_F1E4C0AA_8A3D_4e28_BF8A_07083DD023B5__INCLUDED_)
