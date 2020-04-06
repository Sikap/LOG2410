///////////////////////////////////////////////////////////
//  OccasionalPlanFactory.h
//  Implementation of the Class OccasionalPlanFactory
//  Created on:      10-mars-2020 16:35:35
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_F573D8DF_AF60_4df5_883B_AA1FB1B29984__INCLUDED_)
#define EA_F573D8DF_AF60_4df5_883B_AA1FB1B29984__INCLUDED_

#include "AbsPlanFactory.h"

namespace PolyCharge
{
	class OccasionalPlanFactory : public AbsPlanFactory
	{

	public:
		OccasionalPlanFactory() = default;
		virtual ~OccasionalPlanFactory() = default;

		virtual class AbsSubscriptionPlan* createPlan() const;
	};
}
#endif // !defined(EA_F573D8DF_AF60_4df5_883B_AA1FB1B29984__INCLUDED_)
