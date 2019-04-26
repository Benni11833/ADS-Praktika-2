/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

#define Max_Ring_Size 6

void Ring::incrementAges() {
	RingNode* run_ptr = anker_;
	while (run_ptr->getNext() != anker_) {
		run_ptr->setAge(run_ptr->getAge() + 1);
		run_ptr = run_ptr->getNext();
	}
}

RingNode* Ring::getOldestNode(){
	RingNode* run_ptr = anker_, *oldest_Node = anker_;
	while(run_ptr->getNext() != anker_){
		if(run_ptr->getAge() > oldest_Node->getAge())
			oldest_Node = run_ptr;
		run_ptr = run_ptr->getNext();
	}
	return oldest_Node;
}

RingNode* Ring::getPredecessor(RingNode* tmp){
	if(tmp == nullptr)
		return nullptr;
	else{
		RingNode* run_ptr = anker_;
		while(run_ptr->getNext() != anker_){
			if(run_ptr->getNext() == tmp)
				return run_ptr;
			run_ptr = run_ptr->getNext();
		}
		std::cerr << "Fehler in Methode getPredecessor: tmp hat keinen vorgaenger\n";
		return nullptr;
	}
}

RingNode* Ring::getLast(){
	RingNode* run_ptr = anker_;
	while(run_ptr->getNext() != anker_)
		run_ptr = run_ptr->getNext();
	return run_ptr;
}



Ring::Ring() 
	:anker_{ nullptr }
{
	anker_->setNext(anker_);
}

Ring::~Ring(){
	RingNode* run = anker_, *run2 = anker_;
	while(run->getNext() != anker_){
		run2 = run;
		delete run;
		run = run2->getNext();
	}
	delete run;
}

void Ring::addNode(std::string description, std::string symbolic_data) {
	RingNode* new_entry = new RingNode{ 0, description, symbolic_data };
	if (anker_ == nullptr) {
		anker_ = new_entry;
		anker_->setNext(anker_);
	}else{
		if(Anzahl_Nodes_ < Max_Ring_Size){
			//new_entry am ende einfuegen
			getLast()->setNext(new_entry);
			new_entry->setNext(anker_);
		}else{
			RingNode* oldest = getOldestNode();
			RingNode* nach_oldest = oldest->getNext();
			RingNode* vor_oldest = getPredecessor(oldest);
			
		}
	}
}

bool Ring::search(std::string symbolic_data)const {

}

void Ring::print()const {
	
}
