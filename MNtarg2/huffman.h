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
#pragma region fields
	priority_queue<Node*, vector<Node*>, compareNode> pq;
	Node* root;
	list<letter> lOL;
#pragma endregion


	void listOfLetters(string); // build list from each letter (char) each that in code
	void buildPQ(); // build priority queue
	void buildTree(); // build huffman tree by using data from priority queue
	void upgradeBinCode(); // updating binary code for each letter in list of letters

	
	void kidud(Node*); // func build structure of huffman tree

	bool findCharInStr(string, string); // help func that help to find char in some string
	void encode(string); // func output encoded message of inputed word
	void decodeTree(Node*&,string&, string&); // func build tree for decode by using iputed struct and word`s in code
public:
	HuffmanTree();
	~HuffmanTree();
	

	//Encode task
	void buildProcces(string);
	void runTask(string);

	//Decode task
	void buildDecode(string, string);
	void runDecode(string);
};

