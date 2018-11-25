#include "huffman.h"
#include <iostream>

// build priority queue
void HuffmanTree::buildPQ()
{
	for (letter i : lOL)
	{
		Node* temp = new Node(i);
		pq.push(temp);
	}
	return;
}

void HuffmanTree::buildTree()
{
	Node *tmp1, *tmp2, *tmp;
	while (pq.size() > 1)
	{
		//get the smalles values
		tmp1 = pq.top();
		pq.pop();
		tmp2 = pq.top();
		pq.pop();

		//contect the nodes into one node and enter to the queue
		tmp = new Node;
		tmp->_nLetter = tmp2->_nLetter + tmp1->_nLetter;
		tmp->_right = tmp1;
		tmp->_left = tmp2;


		pq.push(tmp);
	}
	root = pq.top();
	return;
}



HuffmanTree::HuffmanTree()
{
	root = NULL;
}

HuffmanTree::~HuffmanTree()
{
	delete root;
}

// func create program backend for encode
void HuffmanTree::buildProcces(string word)
{
	listOfLetters(word);
	buildPQ();
	buildTree();
	upgradeBinCode();
	return;
}

// output of program for encode
void HuffmanTree::runTask(string word)
{
	cout << lOL.size() << endl;
	kidud(root); cout << endl;
	cout << root->_nLetter.getStr() << endl;
	encode(word); cout << endl;
	return;
}

// func create program backend for decode
void HuffmanTree::buildDecode(string letters, string treeStruct)
{
	listOfLetters(letters);
	decodeTree(root, treeStruct, letters);
	upgradeBinCode();
}

// output of program for decode
void HuffmanTree::runDecode(string bCode)
{
	string tmp;
	while (bCode.size() > 0)
	{
		tmp += bCode[0];
		for (letter i : lOL)
		{
			if (i.getBCode() == tmp)
			{
				cout << i.getStr();
				tmp = "";
			}
		}
		bCode.erase(0, 1);
	}
}


// build list from each letter (char) each that in code
void HuffmanTree::listOfLetters(string word)
{
	list<letter> listLetter;

	int size = word.size();
	int count = 1; // help value for calc frequency of each char
	char space = (char)32; //help char - "space"
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if ((word[i] == word[j]) && (word[j] != space) && (word[i] != space))
			{
				count++;
				/*detect same char by changing him to space*/
				word[j] = space; 
			}
		}
		// push char and his freq to list
		if ((word[i] != space)) {
			letter temp(word[i], count);
			listLetter.push_front(temp);

			count = 1; //refresh count for next char
		}
	}

	// sort this list and initilaze in huffman field
	listLetter.sort();
	lOL = listLetter;
	return;
}

// func build structure of huffman tree
void HuffmanTree::kidud(Node* n)
{
	// if comes to leaf ->output 1
	if ((n->_left == NULL) && (n->_right == NULL))
	{
		cout << "1";
		return;
	}
	//else output 0 and still go to leaf
	else
	{
		cout << "0";
		kidud(n->_left);
		kidud(n->_right);

		return;
	}
}

// updating binary code for each letter in list of letters
void HuffmanTree::upgradeBinCode()
{
	Node* tmp;
	// for each letter in list of letter`s do:
	for (letter &i : lOL)
	{
		tmp = root;
		// do while comes to leaf
		while ((tmp->_left != NULL) && (tmp->_right != NULL))
		{
			//if found same chars in right node
			if (findCharInStr(i.getStr(), tmp->_right->_nLetter.getStr()))
			{
				i.setBCode("1"); // update letter`s bin code by adding him "1"
				tmp = tmp->_right; // go to right
			}
			// else chars are in left node
			else
			{
				i.setBCode("0");// update letter`s bin code by adding him "0"
				tmp = tmp->_left; // go to left
			}
		}
	}
	return;
}

// help func that help to find char in some string
bool HuffmanTree::findCharInStr(string chr, string str)
{

	for (int i = 0; i < str.size(); i++)
	{
		if (chr[0] == str[i])
			return true;
	}
	return false;
}

// func output encoded message of inputed word
void HuffmanTree::encode(string word)
{
	// for each char in word
	for (int i = 0; i < word.size(); i++)
	{
		//find same char in list of letters
		for (letter j : lOL)
		{
			if (j.getStr()[0] == word[i])
			{
				// print his binary code
				cout << j.getBCode();
			}
		}
	}
	return;
}

// func build tree for decode by using iputed struct and word`s in code
void HuffmanTree::decodeTree(Node* &n, string &tStruct, string &letters)
{
	if (tStruct.size() != 0) // while struct of tree not empty
	{
		if (tStruct[0] == '0') // if first char is "0"
		{
			n = new Node(letters); // create new node in tree
			tStruct.erase(0, 1); // detele firt char in struct
			decodeTree(n->_left, tStruct, letters); // still to decode struct in left side
			decodeTree(n->_right, tStruct, letters); // still to decode struct in right side
			// update Node name letter from his updated sons
			n->_nLetter.setStr(n->_left->_nLetter.getStr() + n->_right->_nLetter.getStr()); 
			return;
		}
		if (tStruct[0] == '1') // if first char is "1" - we comes to leaf
		{
			n = new Node(letters.front()); // create new node, give him name of first char in inputed word, son`s are NULL
			letters.erase(0, 1); // detele firt char in struct
			tStruct.erase(0, 1); // detele firt char in inputed word
			return;
		}
	}
	return;
}