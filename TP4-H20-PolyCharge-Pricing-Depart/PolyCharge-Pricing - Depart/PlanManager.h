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

#include "AbsSubscriptionPlan.h"
#include "AbsRebateDecorator.h"
#include "AbsPlanFactory.h"
#include "AbsRebateFactory.h"

namespace PolyCharge
{
	using PlanPointer = std::unique_ptr<AbsSubscriptionPlan>;
	using PlanContainer = std::vector<PlanPointer>;
	using PlanIterator = PlanContainer::iterator;
	using PlanConstIterator = PlanContainer::const_iterator;

	using PlanFactoryPointer = std::unique_ptr<AbsPlanFactory>;
	using PlanFactoryContainer = std::unordered_map<std::string, PlanFactoryPointer>;

	using RebateFactoryPointer = std::unique_ptr<AbsRebateFactory>;
	using RebateFactoryContainer = std::unordered_map<std::string, RebateFactoryPointer>;

	class PlanManager
	{

	public:
		PlanManager() = default;
		virtual ~PlanManager() = default;

		virtual void addPlanFactory(std::string factoryName, AbsPlanFactory* factoryp);
		virtual void addRebateFactory(std::string factoryName, AbsRebateFactory* factoryp);
		virtual AbsSubscriptionPlan& createPlan(std::string planName);
		virtual AbsSubscriptionPlan& createRebatePlan(std::string planName, std::string rebateName);

		PlanIterator begin();
		PlanIterator end();
		PlanConstIterator cbegin() const;
		PlanConstIterator cend() const;

	protected:
		PlanContainer m_plans;
		PlanFactoryContainer m_planFactorys;
		RebateFactoryContainer m_rebateFactorys;
	};
}
#endif // !defined(EA_8EDA1466_8327_443d_89D1_98378ACE6CD0__INCLUDED_)
