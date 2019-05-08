/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;


void Tree::printLevelOrder(void)
{
	TreeNode *k = anker, *node = nullptr;
	std::queue<TreeNode*> q;
	if (anker) {
		q.push(anker);
		while (!q.empty()) {
			TreeNode *node = q.front();
			node->print();
			q.pop();

			//enqueue left child
			if (node->getLeft())
				q.push(node->getLeft());
			
			//enqueue right child
			if (node->getRight())
				q.push(node->getRight());
		}
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
	/*rekursiv:
	if (tmp) {
		tmp->print();
		print_preorder(tmp->getLeft());
		print_preorder(tmp->getRight());
	}*/
	//iterativ
	if (anker) {
		std::stack<TreeNode*> s;
		tmp = anker;
		s.push(anker);
		while (!s.empty()) {
			tmp = s.top();	s.pop();
			tmp->print();
			if (tmp->getRight())
				s.push(tmp->getRight());
			if (tmp->getLeft())
				s.push(tmp->getLeft());
		}
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
		while (found && PosID != found->getNodePosID()) {	//found und parent suchen
			parent = found;
			if (PosID < found->getNodePosID())
				found = found->getLeft();
			else
				found = found->getRight();
		}
		if (found) {

		if (isLeaf(found)) {
				if (isRoot(found)/*|| !parent*/)	//wenn Root einziger Eintrag ist -> nullptr
					anker = nullptr;
				else if (parent->getRight() == found)	//knoten, auf dem parent von found zeigte auf nullptr setzten
					parent->setRight(nullptr);
				else
					parent->setLeft(nullptr);
				delete found;
			}//if(isLeaf(found))
			else if (has1Child(found)) {	//1 Kind
				if (isRoot(found)) {	//wenn Wurzel, einziges Kind wird zur neuen wurzel
					if (found->getRight())
						anker = found->getRight();
					else
						anker = found->getLeft();
					return;
				}

				if (parent->getRight() == found)	//Kinderknoten umbiegen des parents von found
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
				TreeNode *min = Min(found->getRight()), *min_parent = getParent(min);
				if (has1Child(min) && !isRoot(min_parent))	//wenn min noch rechtes kind hat
					min_parent->setLeft(min->getRight());	//umbiegen von min_parent auf das rechte Kind
				else if(min_parent != found && !isRoot(min_parent))	//sonst wird found ueberschrieben und spaeter falsch umgebogen
					min_parent->setLeft(nullptr);
				if(!isRoot(min_parent))	//sonst wird ueberschrieben(min zeigt sonst auf sich selbst)
					min->setRight(found->getRight());
				min->setLeft(found->getLeft());	//min->left auf found->left umbiegen
				if (parent && parent->getRight() == found)	//parent->kind umbiegen
					parent->setRight(min);
				else if(parent)
					parent->setLeft(min);
				if (isRoot(found))	//wenn found wurzel ist, anker auf neue wurzel setzten, sonst anker == 0dddddd...
					anker = min;
				delete found;
			}//else if(has2child(found))

		}//if(found)
	}//if(anker)
}

bool Tree::searchNode(std::string Name)
{
	bool flag{ false };
	if (anker) {
		TreeNode *k{ anker };
		std::queue<TreeNode*> q;
		q.push(anker);
		while (!q.empty()) {
			k = q.front();
			q.pop();
			if (k->getName() == Name) {
				flag = true;
				std::cout << "NodeID: " << k->getNodeID() << ", Name: " << k->getName()
					<< ", Alter: " << k->getAlter() << ", Einkommen: " << k->getEinkommen()
					<< ", PLZ: " << k->getPLZ() << ", PosID: " << k->getNodePosID()
					<< std::endl;
			}
			if(k->getRight())
				q.push(k->getRight());
			if(k->getLeft())
				q.push(k->getLeft());
		}
	}
	return flag;
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
