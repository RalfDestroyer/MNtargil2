#pragma once
#include<string>

using namespace std;
class letter
{
private:
#pragma region fields
	string _str;
	int _freq;
	string bCode;
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

	letter& operator=(letter);
	bool operator>(letter);
	bool operator<(letter);
	letter operator+(letter);
	
	letter(string str = "NONAME", int freq = 0);
	letter(char _char, int freq = 0);
	~letter();
};

