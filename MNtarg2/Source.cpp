#include <iostream>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include "huffman.h"

using namespace std;

// Rafael Lerman t.z. 327367488
int main()
{
	HuffmanTree tree;

	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";

	int choice;
	do
	{
		cin >> choice;
		string word;
		switch (choice)
		{
		case 1:
			cout << "enter the original text" << endl;
			cin >> word;

			cout << "The encoded string is:" << endl;
			
			tree.buildProcces(word);
			tree.runTask(word);

			break;
		case 2:
			int n;
			string letters, treeStruct, bCode;
			cout << "enter n ";
				cin >> n; 
			cout << "enter the letters ";
				cin >> letters;
			cout << "enter the encoded structure ";
				cin >> treeStruct;
			cout << "enter the encoded text ";
				cin >> bCode;


			cout << "The decoded string is:" << endl;
			tree.buildDecode(letters, treeStruct);
			tree.runDecode(bCode);

			break;
		}

	} while (choice != 3);
	return 0;
}