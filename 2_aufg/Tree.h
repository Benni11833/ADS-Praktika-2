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
	bool rec_searchNode(TreeNode* tmp, std::string Name);
	TreeNode* searchNode(int NodePosID);
	bool isLeaf(TreeNode*);
	bool isRoot(TreeNode*);
	bool has2Child(TreeNode*);
	bool has1Child(TreeNode*);
	TreeNode* Min(TreeNode*);
	void print_preorder(TreeNode*);
	TreeNode* getParent(TreeNode *);
public:
	Tree();
	void addNode(std::string Name, int Alter, double Einkommen, int PLZ);
	void deleteNode(int PosID);
	bool searchNode(std::string Name);
	void printAll();
	// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};
