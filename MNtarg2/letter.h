#pragma once
#include<string>

using namespace std;
class letter
{
private:
#pragma region fields
	string _str; // char of letter
	int _freq; // frequency of letter
	string bCode; // binary code of letter
#pragma endregion

public:
#pragma region get&set
	string getStr();
	int getFreq();
	string getBCode();
	char getBCodeChr();

	void setBCode(string);
	void setStr(string);
	void setStr(char chr);
	void setFreq(int);
#pragma endregion

#pragma region operators
	letter& operator=(letter);
	bool operator>(letter);
	bool operator<(letter);
	letter operator+(letter);
#pragma endregion

#pragma region ctors
	letter(string str = "NONAME", int freq = 0);
	letter(char _char, int freq = 0);
	~letter();
#pragma endregion
};

