///////////////////////////////////////////////////////////
//  AbsPlanFactory.h
//  Implementation of the Class AbsPlanFactory
//  Created on:      10-mars-2020 16:35:22
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_AA2C6F0E_642A_4f5a_B289_CA2071D264D6__INCLUDED_)
#define EA_AA2C6F0E_642A_4f5a_B289_CA2071D264D6__INCLUDED_

#include <string>

namespace PolyCharge
{
	class AbsPlanFactory
	{

	public:
		AbsPlanFactory() = default;
		virtual ~AbsPlanFactory() = default;
		virtual class AbsSubscriptionPlan* createPlan() const = 0;

	protected:
		virtual void registerFactory(std::string name, AbsPlanFactory* factoryp);
	};
}
#endif // !defined(EA_AA2C6F0E_642A_4f5a_B289_CA2071D264D6__INCLUDED_)
