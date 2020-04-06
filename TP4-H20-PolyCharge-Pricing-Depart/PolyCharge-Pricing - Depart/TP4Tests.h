///////////////////////////////////////////////////////////
//  TP4Tests.h
//  Implementation of the Class TP4Tests
//  Created on:      08-mars-2020 17:17:37
//  Original author: francois
///////////////////////////////////////////////////////////

#if !defined(EA_C14AC5D4_4E63_462e_9CDB_3D51133990C4__INCLUDED_)
#define EA_C14AC5D4_4E63_462e_9CDB_3D51133990C4__INCLUDED_

#include "PolyChargePricing.h"
#include "PlanManager.h"

namespace PolyCharge
{
	class TP4Tests
	{

	public:
		TP4Tests();
		virtual ~TP4Tests() = default;

		void testDecorator();
		void testVisitor();

	protected:
		PlanManager m_planMngr;

		bool m_extendedTests;
		bool compareEqual(float a, float b);
	};
}
#endif // !defined(EA_C14AC5D4_4E63_462e_9CDB_3D51133990C4__INCLUDED_)
