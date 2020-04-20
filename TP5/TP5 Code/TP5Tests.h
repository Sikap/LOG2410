///////////////////////////////////////////////////////////
//  TP5Tests.h
//  Implementation of the Class TP5Tests
//  Created on:      08-mars-2020 17:17:37
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_C14AC5D4_4E63_462e_9CDB_3D51133990C4__INCLUDED_)
#define EA_C14AC5D4_4E63_462e_9CDB_3D51133990C4__INCLUDED_

#include "PolyChargePricing.h"

namespace PolyCharge
{
	class TP5Tests
	{

	public:
		TP5Tests() = default;
		virtual ~TP5Tests() = default;

		void testFactory();
		void testSingleton();
		void testMediator();
		void testFacade();

	protected:
		PolyChargePricing m_pricing;
	};
}
#endif // !defined(EA_C14AC5D4_4E63_462e_9CDB_3D51133990C4__INCLUDED_)
