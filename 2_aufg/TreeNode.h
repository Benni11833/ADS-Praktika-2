/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include <iomanip>

#define setw_width 5
#define setw_width2 8
using namespace std;

class TreeNode{
	
	private:
		int NodePosID;
		int NodeID;
		std::string Name;
		int Alter;
		double Einkommen;
		int PLZ;
		TreeNode* left, *right;
	
	public:
		TreeNode(int NodePosID, int NodeID, std::string Name, 
						int Alter, double Einkommen, int PLZ);
		//Getter-/Setter
		int getNodePosID();
		int getNodeID();
		std::string getName();
		void setName(std::string);
		int getAlter();
		void setAlter(int);
		double getEinkommen();
		void setEinkommen(double);
		int getPLZ();
		void setPLZ(int);
		TreeNode* getLeft();
		TreeNode* getRight();
		void setLeft(TreeNode*);
		void setRight(TreeNode*);
		void print();
};
