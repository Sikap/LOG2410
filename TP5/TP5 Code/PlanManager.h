///////////////////////////////////////////////////////////
//  PlanManager.h
//  Implementation of the Class PlanManager
//  Created on:      08-mars-2020 16:18:47
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_8EDA1466_8327_443d_89D1_98378ACE6CD0__INCLUDED_)
#define EA_8EDA1466_8327_443d_89D1_98378ACE6CD0__INCLUDED_

#include <vector>
#include <memory>
#include <unordered_map>

#include "IPolyChargePlan.h"
#include "AbsSubscriptionPlan.h"
#include "AbsRebateDecorator.h"
#include "AbsPlanFactory.h"
#include "AbsRebateFactory.h"

namespace PolyCharge
{
	using PlanFactoryPointer = AbsPlanFactory*;
	using PlanFactoryContainer = std::unordered_map<std::string, PlanFactoryPointer>;

	class PlanManager
	{

	public:
		static PlanManager& getInstance(void);

		virtual void addPlanFactory(std::string factoryName, PlanFactoryPointer factoryp);
		virtual void createAllPlans(void);
		virtual AbsSubscriptionPlan& findPlan(const std::string& planName);

		PlanIterator begin();
		PlanIterator end();
		PlanConstIterator cbegin() const;
		PlanConstIterator cend() const;

	protected:
		virtual ~PlanManager();
		PlanManager() = default;

		PlanContainer m_plans;
		PlanFactoryContainer m_planFactorys;
	};
}
#endif // !defined(EA_8EDA1466_8327_443d_89D1_98378ACE6CD0__INCLUDED_)
