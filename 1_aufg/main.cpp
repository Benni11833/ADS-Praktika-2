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
	int result = Catch::Session().run();
	// Ihr Code hier:
	system("pause");
	return 0;
	/*int x{ 0 };
	std::string desc{ "" }, data{ "" };
	Ring r1;

	printmenu();

	while (true) {
		std::cin >> x;
		switch (x) {
		case 1:
			std::cout << "+Neuen Datensatz einfuegen" << std::endl
				<< "Beschreibung ?> "; 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	std::getline(std::cin, desc);
			std::cout << "Daten ?> ";		std::getline(std::cin, data);
			r1.addNode(desc, data);
			std::cout << "+Ihr Datensatz wurde hinzugefuegt." << std::endl << "?> ";
			break;
		
		case 2:
			std::cout << "+Nach welchen Daten soll gesucht werden?"
				<< std::endl << "?> ";	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');		std::getline(std::cin, data);
			if (!r1.search(data)) {
				std::cout << "+ Datensatz konnte nicht gefunden werden." << std::endl << "?> ";
			}
			else {
				std::cout << "?> ";
			}
			break;

		case 3:
			r1.print();
			std::cout << "?> ";
			break;
		default:
			std::cout << "?> ";
			break;
		}
	}*/
	Ring rloop;
	int n{0};
	std::cout << "n: ";
	std::cin >> n;
	for(int i=0; i < n; i++)
		rloop.addNode("Descri"+std::to_string(i), "Data"+std::to_string(i));
	
	rloop.printTest();
	std::cout << "AnzahlNode - sollte " << n << " sein: " << rloop.size() << std::endl;

	//
	///////////////////////////////////////
	//system("Pause");
	return 0;
}
