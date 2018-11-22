#pragma once
#include <iostream>
#include <queue>
#include <list>
#include <string>
#include "Node.h"

using namespace std;


class compareNode
{
public:
	bool operator()(Node* const& n1, Node* const& n2)
	{
		return (n1->_nLetter > n2->_nLetter);
	}
};

class HuffmanTree
{
private:
	priority_queue<Node*, vector<Node*>, compareNode> pq;
	Node* root;
	list<letter> lOL;

	void buildPQ();
	void buildTree();
	void listOfLetters(string);
	void kidud(Node*);
	void upgradeBinCode();
	bool findCharInStr(string, string);
	void encode(string);
	void decodeTree(Node*&,string&, string&);
	void buildTreeForDecode(Node*&,string&);
public:
	
	HuffmanTree();
	~HuffmanTree();
	void buildProcces(string);
	void runTask(string);

	void buildDecode(string, string);
	void runDecode(string);
};

