/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>

class RingNode{
	
private:
	// Ihr Code hier:
	int old_age_;
	std::string description_;
	std::string symbolic_data_;
	RingNode* next_;
	//	
public:
	// Ihr Code hier:
	RingNode();
	RingNode(int oldage, std::string description, std::string symbolic_data);
	int getAge()const;
	void setAge(int new_age);
	std::string getDescription()const;
	void setDescription(std::string description);
	std::string getData()const;
	void setData(std::string new_symbolic_data);
	RingNode* getNext()const;
	void setNext(RingNode* new_next);
	//
};
