// PolyCharge-CLI.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "TP5Tests.h"

using PolyCharge::TP5Tests;

int main()
{
    std::cout << "TP5 --- Execution des tests\n";

	TP5Tests tp5;
	try {
		tp5.testFactory();
		tp5.testSingleton();
		tp5.testMediator();
		tp5.testFacade();
	}

	catch (std::exception& e)
	{
		std::cerr << "Exception levée: " << e.what() << std::endl;
	}
}
