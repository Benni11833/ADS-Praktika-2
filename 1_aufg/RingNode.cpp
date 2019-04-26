/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"

std::string line(50, '-');

RingNode::RingNode() 
	:old_age_{ 0 }, description_{ "X" }, symbolic_data_{ "empty" }, next_{ nullptr }
{}

RingNode::RingNode(int oldage, std::string description, std::string symbolic_data)
	: old_age_{ oldage }, description_{ description }, symbolic_data_{ symbolic_data }, next_{ nullptr }
{}

int RingNode::getAge()const { return old_age_; }

void RingNode::setAge(int new_age) {
	old_age_ = new_age;
}

std::string RingNode::getDescription()const{ return description_; }

void RingNode::setDescription(std::string description){
	description_ = description;
}

std::string RingNode::getData()const { return symbolic_data_; }

void RingNode::setData(std::string new_symbolic_data) {
	symbolic_data_ = new_symbolic_data;
}

RingNode* RingNode::getNext()const { 
	return next_; 
}

void RingNode::setNext(RingNode* new_next) {
	next_ = new_next;
}

std::ostream& operator<<(std::ostream& os, RingNode* node){
	os << line << std::endl << "Adresse: " << &node
	<< std::endl << "Age: " << node->old_age_
	<< std::endl << "Description: " << node->description_
	<< std::endl << "Data: " << node->symbolic_data_
	<< std::endl << "Adresse-Next: " << &(node->next_)
	<< std::endl << std::endl;

	return os;
}