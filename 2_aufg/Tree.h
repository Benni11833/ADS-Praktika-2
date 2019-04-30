/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

using namespace std;


class Tree {
private:
	TreeNode * anker;
	int NodeIDCounter;
public:
	Tree();
	void addNode(std::string Name, int Alter, double Einkommen, int PLZ);
	void deleteNode(int PosID);
	bool searchNode(std::string Name);
	void printAll();
	// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};
