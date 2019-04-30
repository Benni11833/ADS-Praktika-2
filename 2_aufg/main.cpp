/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

void printmenu() {
	std::cout << "1) Datensatz einfuegen, manuell" << std::endl
		<< "2) Datensatz einfuegen, CSV Datei" << std::endl
		<< "3) Datensatz loschen" << std::endl
		<< "4) Suchen" << std::endl
		<< "5) Datenstruktur anzeigen" << std::endl;
}

void readData(std::string& name, int& alter, double& einkommen, int& plz) {
	std::cout << "+ Bitte geben Sie die den Datensatz ein" << std::endl
		<< "Name ?> ";	std::getline(std::cin, name);
	std::cout << "Alter ?>";	std::cin >> alter;			std::cout << std::endl;
	std::cout << "Einkommen ?>";	std::cin >> einkommen;	std::cout << std::endl;
	std::cout << "PLZ ?>";	std::cin >> plz;				std::cout << std::endl;
}

int main() {

	//int result = Catch::Session().run();

	Tree t1;
	t1.addNode("Dieter", 99, -52.32, 52066);
	int choice{ -1 };
	printmenu();
	std::string name{ "" };
	int alter{ 0 }, plz{ 0 };	double einkommen{ 0.00 };

	while (true) {
		std::cout << "?>";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (choice) {
		case 1:
			readData(name, alter, einkommen, plz);
			t1.addNode(name, alter, einkommen, plz);
			std::cout << "+ Ihr Datensatz wurde eingefuegt" << std::endl;
			break;
		case 2:
			std::cout << "Noch nicht fertig...\n";
			std::cin.get();
			break;
		case 3:
			std::cout << "+ Bitte geben Sie den zu loschenden Datensatz an" << std::endl
				<< "PosID ?>";	std::cin >> alter;
			t1.deleteNode(alter);
			std::cout << "+ Datensatz wurde geloscht." << std::endl;
			break;
		case 4:
			std::cout << "+ Bitte geben Sie den zu suchenden Datensatz an"
				<< std::endl << "Name ?>";	std::getline(std::cin, name);
			std::cout << "+ Fundstellen:" << std::endl;
			if (!t1.searchNode(name))
				std::cout << "Keine Treffer" << std::endl;
			break;
		case 5:
			t1.printAll();
			break;
		default:
			std::cout << "?> ";
			break;
		}
	}

	system("PAUSE");

	return 0;
}
