/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.hpp"

using namespace std;

void printmenu() {
	std::cout << "1) Backup einfuegen" << std::endl
		<< "2) Backup suchen" << std::endl
		<< "3) Alle Backups ausgeben" << std::endl <<
		"?>";
}

int main()
{
	//int result = Catch::Session().run();
	// Ihr Code hier:
	int x{ 0 };
	std::string desc{ "" }, data{ "" };
	Ring r1;

	printmenu();

	while (true) {
		std::cin >> x;
		switch (x) {
		case 1:
			std::cout << "+Neuen Datensatz einfuegen" << std::endl
				<< "Beschreibung ?> "; std::getline(std::cin, desc);
			std::cout << "Daten ?> ";	std::getline(std::cin, data);
			r1.addNode(desc, data);
			std::cout << "+Ihr Datensatz wurde hinzugefuegt." << std::endl;
			break;
		
		case 2:

			break;
		}
	}

	//
	///////////////////////////////////////
	system("Pause");
	return 0;
}
