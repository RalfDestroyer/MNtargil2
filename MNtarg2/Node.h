#pragma region Node
#include "letter.h"

class Node
{
public:
	letter _nLetter;
	Node* _left;
	Node* _right;

	//ctors
	Node();
	Node(letter nLetter);
	Node(letter nLetter, Node* left, Node* right);
	~Node();
	
	//operators
	bool operator>(Node);
	Node operator = (Node);
};

