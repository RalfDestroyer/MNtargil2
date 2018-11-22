#include "Node.h"




Node::Node()
{
	letter temp;
	this->_nLetter = temp;
	this->_left = NULL;
	this->_right = NULL;
}

Node::Node(letter nLetter)
{
	_nLetter = nLetter;
	_left = NULL;
	_right = NULL;
}

Node::Node(letter nLetter, Node * left, Node * right)
{
	_nLetter = nLetter;
	_left = left;
	_right = right;
}

Node::~Node()
{
	delete _left;
	delete _right;
}

bool Node::operator>(Node another)
{
	return (this->_nLetter > another._nLetter);
}

Node Node::operator=(Node another)
{
	this->_nLetter = another._nLetter;
	return *this;
}


