///////////////////////////////////////////////////////////
//  RebateManager.h
//  Implementation of the Class RebateManager
//  Created on:      03-avr.-2020 15:44:39
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_0F997877_84D7_4fc2_8E1A_CA00FC3BEF95__INCLUDED_)
#define EA_0F997877_84D7_4fc2_8E1A_CA00FC3BEF95__INCLUDED_

#include <vector>
#include <memory>
#include <unordered_map>

#include "IPolyChargeRebate.h"
#include "AbsRebateDecorator.h"
#include "AbsRebateFactory.h"

namespace PolyCharge
{
	class RebateManager
	{
	public:
		static RebateManager& getInstance(void);

		virtual void addRebateFactory(std::string factoryName, AbsRebateFactory* factoryp);
		virtual AbsRebateDecorator& createRebate(const std::string& RebateName, AbsSubscriptionPlan& plan, float percentRebate = 0.05f);

		RebateTypeIterator rebateType_begin();
		RebateTypeIterator rebateType_end();
		RebateTypeConstIterator rebateType_cbegin() const;
		RebateTypeConstIterator rebateType_cend() const;

		RebateIterator rebate_begin();
		RebateIterator rebate_end();
		RebateConstIterator rebate_cbegin() const;
		RebateConstIterator rebate_cend() const;

	protected:
		virtual ~RebateManager() = default;
		RebateManager() = default;

		RebateContainer m_rebates;
		RebateFactoryContainer m_rebateFactorys;
	};
}
#endif // !defined(EA_0F997877_84D7_4fc2_8E1A_CA00FC3BEF95__INCLUDED_)
