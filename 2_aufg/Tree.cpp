/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>

using namespace std;


bool Tree::rec_searchNode(TreeNode* tmp, std::string Name)
{
	static bool flag{ false };
	if (tmp == anker)	//wenn flag auf true steht von vorherigen aufrufen
		flag = false;
	if (tmp) {
		if (tmp->getName() == Name) {
			flag = true;
			std::cout << "NodeID: " << tmp->getNodeID() << ", Name: " << tmp->getName()
				<< ", Alter: " << tmp->getAlter() << ", Einkommen: " << tmp->getEinkommen()
				<< ", PLZ: " << tmp->getPLZ() << ", PosID: " << tmp->getNodePosID()
				<< std::endl;
		}
			//Teilbaum weiter durchlaufen - links,rechts
			rec_searchNode(tmp->getLeft(), Name);
			rec_searchNode(tmp->getRight(), Name);
		
		if (tmp == anker)
			return flag;	//baum wurde durchlaufen
	}
}

bool Tree::isLeaf(TreeNode* tmp) {
	return (!tmp->getRight() && !tmp->getLeft());
}

bool Tree::isRoot(TreeNode* tmp) {
	return (anker == tmp);
}

bool Tree::has2Child(TreeNode* tmp) {
	return (tmp->getRight() && tmp->getLeft());
}

bool Tree::has1Child(TreeNode* tmp) {
	return (!has2Child(tmp) && !isLeaf(tmp));
}

void Tree::print_preorder(TreeNode *tmp) {
	if (tmp) {
		tmp->print();
		print_preorder(tmp->getLeft());
		print_preorder(tmp->getRight());
	}
}

TreeNode* Tree::Min(TreeNode* tmp) {	//findet Min vom rechten Teilbaum
	while (tmp->getLeft())
		tmp = tmp->getLeft();
	return tmp;
}

TreeNode* Tree::searchNode(int NodePosID) {	//iterativ - nullptr wenn nicht vorhanden
	TreeNode *x{ anker };
	while (x && NodePosID != x->getNodePosID()) {
		if (NodePosID < x->getNodePosID())
			x = x->getLeft();
		else
			x = x->getRight();
	}
	return x;
}

TreeNode* Tree::getParent(TreeNode *tmp) {
	TreeNode *run{ anker };
	if (isRoot(tmp))
		return nullptr;
	while (run && run->getRight() != tmp && run->getLeft() != tmp) {
		if (tmp->getNodePosID() < run->getNodePosID())
			run = run->getLeft();
		else
			run = run->getRight();
	}
	return run;
}


Tree::Tree()
	:anker{ nullptr }, NodeIDCounter{ 0 }
{}

void Tree::addNode(std::string Name, int Alter, double Einkommen, int PLZ)
{
	int NodePosID = Alter + PLZ + Einkommen;
	TreeNode* new_entry = new TreeNode{ NodePosID, NodeIDCounter++, Name, Alter, Einkommen, PLZ };
		TreeNode* y{ nullptr }, *x{ anker };
		while (x) {
			y = x;
			if (NodePosID < x->getNodePosID())
				x = x->getLeft();
			else
				x = x->getRight();
		}
		if (!y)	//anker == nullptr
			anker = new_entry;
		else
			if (NodePosID < y->getNodePosID())
				y->setLeft(new_entry);
			else
				y->setRight(new_entry);
}

void Tree::deleteNode(int PosID)
{
	if (anker) {
		TreeNode *found{ anker }, *parent{ nullptr };
		while (found && PosID != found->getNodePosID()) {
			parent = found;
			if (PosID < found->getNodePosID())
				found = found->getLeft();
			else
				found = found->getRight();
		}
		if (found) {	//kein Kind

			if (isLeaf(found)) {
				if (parent->getRight() == found)
					parent->setRight(nullptr);
				else
					parent->setLeft(nullptr);
				delete found;
			}
			else if (has1Child(found)) {	//1 Kind
				if (parent->getRight() == found)
					if (found->getRight())
						parent->setRight(found->getRight());
					else
						parent->setRight(found->getLeft());
				else
					if (found->getRight())
						parent->setLeft(found->getRight());
					else
						parent->setLeft(found->getLeft());
				delete found;
			}//else if(has1Child(found))
			else if (has2Child(found)) {
				TreeNode *min = Min(found->getRight());
				if (has1Child(min))	//wenn min noch rechte kinder hat
					getParent(min)->setLeft(min->getRight());
				min->setRight(found->getRight());
				min->setLeft(found->getLeft());
				if (parent->getRight() == found)
					parent->setRight(min);
				else
					parent->setLeft(min);
				delete found;
			}

		}//if(found)
	}//if(anker)
}

bool Tree::searchNode(std::string Name)
{
	if (anker)
		return rec_searchNode(anker, Name);
	else
		return false;
}

void Tree::printAll()
{
	if (anker == nullptr)
		std::cout << "Kein Eintrag gefunden" << std::endl;
	else {
		TreeNode* run = anker;
		std::cout << "ID" << std::setw(setw_width) << std::right << '|' << "Name" << std::setw(setw_width) << std::right << '|' << "Alter" << std::setw(setw_width) << std::right << '|'
			<< "Einkommen" << std::setw(setw_width) << std::right << '|' << "PLZ" << std::setw(setw_width) << std::right << '|' << "Pos" << std::endl;
		print_preorder(anker);
	}
}
