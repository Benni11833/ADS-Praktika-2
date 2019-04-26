/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.hpp"
#include"RingNode.h"

class Ring {

private:
	int Anzahl_Nodes_;
	RingNode* anker_;
	//Hilfsmethoden
	RingNode* getLast();
	void incrementAges();	//Aktualisiert Alter aller Nodes
	RingNode* getOldestNode();	//Pointer auf aeltesten Knoten
	RingNode* getPredecessor(RingNode* tmp);	//Pointer auf vorgaenger von tmp
public:
	Ring();
	~Ring();
	void addNode(std::string description, std::string symbolic_data);
	bool search(std::string symbolic_data)const;
	void print()const;
	// friend Funktionen m�ssen unangetastet bleiben! 
	friend RingNode * get_anker(Ring& r);
	friend int get_AnzahlNodes(Ring& r);
};