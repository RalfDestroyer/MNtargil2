#include "letter.h"



string letter::getStr()
{
	return _str;
}

int letter::getFreq()
{
	return _freq;
}

string letter::getBCode()
{
	return bCode;
}

char letter::getBCodeChr()
{
	if (bCode.size() == 1)
		return bCode[0];
	else
		return 'F';
}

void letter::setBCode(string bit)
{
	if (bCode == "N")
		bCode = bit;
	else
		bCode += bit;
	return;
}

void letter::setStr(string str)
{
	_str = str;
	return;
}

void letter::setStr(char chr)
{
	_str = chr;
	return;
}

void letter::setFreq(int freq)
{
	_freq = freq;
	return;
}

letter& letter::operator=(letter another)
{
	this->_freq = another._freq;
	this->_str = another._str;
	return *this;
}

bool letter::operator>(letter another)
{
	if (this->_freq > another._freq && this->_str > another._str)
		return true;
	else
		return false;
}

bool letter::operator<(letter another)
{
	if (this->_freq < another._freq)
		return true;
	else
		return false;
}

letter letter::operator+(letter another)
{
	letter temp;
	temp._freq = this->_freq + another._freq;
	temp._str = this->_str + another._str;
	return temp;
}

letter::letter(string str , int freq)
{
	_str = str;
	_freq = freq;
	bCode = "N";
}

letter::letter(char _char, int freq)
{
	_str = _char;
	_freq = freq;
	bCode = "N";
}


letter::~letter()
{
}
