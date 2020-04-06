// PolyCharge-CLI.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "TP4Tests.h"

using PolyCharge::TP4Tests;

int main()
{
    std::cout << "TP4 --- Execution des tests\n";

	TP4Tests tp4;
	try {
		tp4.testDecorator();
		tp4.testVisitor();
	}

	catch (std::exception& e)
	{
		std::cerr << "Exception levée: " << e.what() << std::endl;
	}
}
