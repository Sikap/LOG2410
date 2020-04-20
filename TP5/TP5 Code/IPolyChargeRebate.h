///////////////////////////////////////////////////////////
//  IPolyChargeRebate.h
//  Implementation of the Interface IPolyChargeRebate
//  Created on:      05-avr.-2020 11:22:08
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_6279E6B8_39CF_4b96_AE64_9188C8A6D745__INCLUDED_)
#define EA_6279E6B8_39CF_4b96_AE64_9188C8A6D745__INCLUDED_

#include <string>

#include "PolyCharge.h"

namespace PolyCharge
{
	class AbsRebateDecorator;
	class AbsRebateFactory;

	using RebatePointer = std::unique_ptr<AbsRebateDecorator>;
	using RebateContainer = std::unordered_map<std::string, RebatePointer>;
	using RebateIterator = RebateContainer::iterator;
	using RebateConstIterator = RebateContainer::const_iterator;
	
	using RebateFactoryPointer = AbsRebateFactory*;
	using RebateFactoryContainer = std::unordered_map<std::string, RebateFactoryPointer>;

	// Define an iterator over the keys of the factory map
	class RebateTypeIterator : public RebateFactoryContainer::iterator
	{
	public:
		RebateTypeIterator() : RebateFactoryContainer::iterator() {};
		RebateTypeIterator(RebateFactoryContainer::iterator s) : RebateFactoryContainer::iterator(s) {};
		std::string* operator->() { return (std::string* const)&(RebateFactoryContainer::iterator::operator->()->first); }
		std::string operator*() { return RebateFactoryContainer::iterator::operator*().first; }
	};

	// Define a const_iterator over the keys of the factory map
	class RebateTypeConstIterator : public RebateFactoryContainer::const_iterator
	{
	public:
		RebateTypeConstIterator() : RebateFactoryContainer::const_iterator() {};
		RebateTypeConstIterator(RebateFactoryContainer::const_iterator s) : RebateFactoryContainer::const_iterator(s) {};
		const std::string* operator->() { return (const std::string* const)&(RebateFactoryContainer::const_iterator::operator->()->first); }
		const std::string operator*() { return RebateFactoryContainer::const_iterator::operator*().first; }
	};

	class IPolyChargeRebate
	{

	public:
		virtual class AbsSubscriptionPlan& createRebatePlan(const std::string& planName, const std::string& rebateName, float percentRebate = 0.05f) = 0;

		virtual RebateTypeIterator rebateType_begin() = 0;
		virtual RebateTypeIterator rebateType_end() = 0;
		virtual RebateTypeConstIterator rebateType_cbegin() const = 0;
		virtual RebateTypeConstIterator rebateType_cend() const = 0;

		virtual RebateIterator rebate_begin() = 0;
		virtual RebateIterator rebate_end() = 0;
		virtual RebateConstIterator rebate_cbegin() const = 0;
		virtual RebateConstIterator rebate_cend() const = 0;
	};
}
#endif // !defined(EA_6279E6B8_39CF_4b96_AE64_9188C8A6D745__INCLUDED_)
