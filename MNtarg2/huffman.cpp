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

void HuffmanTree::buildProcces(string word)
{
	listOfLetters(word);
	buildPQ();
	buildTree();
	upgradeBinCode();
	return;
}

void HuffmanTree::runTask(string word)
{
	cout << lOL.size() << endl;
	kidud(root); cout << endl;
	cout << root->_nLetter.getStr() << endl;
	encode(word); cout << endl;
	return;
}

void HuffmanTree::buildDecode(string letters, string treeStruct)
{
	listOfLetters(letters);
	decodeTree(root, treeStruct, letters);
	upgradeBinCode();
}

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



void HuffmanTree::listOfLetters(string word)
{
	list<letter> listLetter;

	int size = word.size();
	int count = 1;
	char space = (char)32; //help char
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

	listLetter.sort();
	//
	//
	lOL = listLetter;
	return;
}

void HuffmanTree::kidud(Node* n)
{
	if ((n->_left == NULL) && (n->_right == NULL))
	{
		cout << "1";
		return;
	}
	else
	{
		cout << "0";
		kidud(n->_left);
		kidud(n->_right);

		return;
	}
}

void HuffmanTree::upgradeBinCode()
{
	Node* tmp;
	for (letter &i : lOL)
	{
		tmp = root;
		while ((tmp->_left != NULL) && (tmp->_right != NULL))
		{
			if (findCharInStr(i.getStr(), tmp->_right->_nLetter.getStr()))
			{
				i.setBCode("1");
				tmp = tmp->_right;
			}
			else
			{
				i.setBCode("0");
				tmp = tmp->_left;
			}
		}
	}
	return;
}

bool HuffmanTree::findCharInStr(string chr, string str)
{

	for (int i = 0; i < str.size(); i++)
	{
		if (chr[0] == str[i])
			return true;
	}
	return false;
}

void HuffmanTree::encode(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		for (letter j : lOL)
		{
			if (j.getStr()[0] == word[i])
			{
				cout << j.getBCode();
			}
		}
	}
	return;
}

void HuffmanTree::decodeTree(Node* &n, string &tStruct, string &letters)
{
	if (tStruct.size() != 0) 
	{
		if (tStruct[0] == '0')
		{
			n = new Node(letters);
			tStruct.erase(0, 1);
			decodeTree(n->_left, tStruct, letters);
			decodeTree(n->_right, tStruct, letters);
			n->_nLetter.setStr(n->_left->_nLetter.getStr() + n->_right->_nLetter.getStr());
			return;
		}
		if (tStruct[0] == '1')
		{
			n = new Node(letters.front());
			letters.erase(0, 1);
			tStruct.erase(0, 1);
			return;
		}
	}
	return;
}

void HuffmanTree::buildTreeForDecode(Node* &n, string &letters)
{
	if ((n->_left == NULL) && (n->_right == NULL))
	{
		n->_nLetter.setStr(letters.front());
		letters.erase(0, 1);
	}
	else
	{
		buildTreeForDecode(n->_left, letters);
		buildTreeForDecode(n->_right, letters);
		return;
	}
}
