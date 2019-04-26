/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>
#include <string>

std::string line(50, '-');

#define Max_Ring_Size 6

void Ring::incrementAges() {
	RingNode* run_ptr = anker;
	while (run_ptr->getNext() != anker) {
		run_ptr->setAge(run_ptr->getAge() + 1);
		run_ptr = run_ptr->getNext();
	}
}

RingNode* Ring::getOldestNode() {
	RingNode* run_ptr = anker, *oldest_Node = anker;
	while (run_ptr->getNext() != anker) {
		if (run_ptr->getAge() > oldest_Node->getAge())
			oldest_Node = run_ptr;
		run_ptr = run_ptr->getNext();
	}
	return oldest_Node;
}

RingNode* Ring::getPredecessor(RingNode* tmp) {
	if (tmp == nullptr)
		return nullptr;
	else {
		RingNode* run_ptr = anker;
		while (run_ptr->getNext() != anker) {
			if (run_ptr->getNext() == tmp)
				return run_ptr;
			run_ptr = run_ptr->getNext();
		}
		std::cerr << "Fehler in Methode getPredecessor: tmp hat keinen vorgaenger\n";
		return nullptr;
	}
}

RingNode* Ring::getLast() {
	RingNode* run_ptr = anker;
	while (run_ptr->getNext() != anker)
		run_ptr = run_ptr->getNext();
	return run_ptr;
}



Ring::Ring()
	:anker{ nullptr }
{}

Ring::~Ring() {
	RingNode* run = anker, *run2 = anker;
	while (run->getNext() != anker) {
		run2 = run;
		run = run->getNext();
		delete run2;
	}
	delete run;
}

void Ring::addNode(std::string description, std::string symbolic_data) {
	RingNode* new_entry = new RingNode{ 0, description, symbolic_data };
	if (anker == nullptr) {
		anker = new_entry;
		anker->setNext(anker);
		++AnzahlNodes;
	}
	else {
		if (AnzahlNodes < Max_Ring_Size) {
			//new_entry am ende einfuegen
			getLast()->setNext(new_entry);
			new_entry->setNext(anker);
			++AnzahlNodes;
		}
		else {	//aeltesten loeschen
			RingNode* oldest = getOldestNode();
			new_entry->setNext(getOldestNode()->getNext());
			getPredecessor(getOldestNode())->setNext(new_entry);
			delete oldest;
		}
		incrementAges();
	}
}

bool Ring::search(std::string symbolic_data)const {
	if (AnzahlNodes == 0)
		return false;
	RingNode* run = anker;
	do {
		if (run->getData() == symbolic_data) {
			std::cout << "+ Gefunden in Backup: OldAge " << run->getAge() << ", Beschreibung: "
			<< run->getDescription() << ", Daten: " << run->getData() << std::endl;
			return true;
		}
		run = run->getNext();
	} while (run != anker);
	return false;
}

void Ring::print()const {
	int n{ 0 };
	if (AnzahlNodes == 0)
		std::cout << "Liste enthaelt keine Elemente" << std::endl;
	else {
		RingNode* run = anker;
		while (n++ < AnzahlNodes){
			run = anker;
			do {
				if (run->getAge() == n - 1) {
					std::cout << "OldAge: " << n - 1 << ", Descr: "
						<< run->getDescription() << ", Data: " << run->getData()
						<< std::endl << line << std::endl;
					break;
				}
				run = run->getNext();
			} while (run != anker);
		}	//end while(n++ < AnzahlNodes)
	}
}