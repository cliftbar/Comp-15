//dictionary.h

#ifndef DICTIONARY
#define DICTIONARY
#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std;

class Dictionary
{
public:
	Dictionary();
	bool insert(string s);
	bool isPrefix(string s);
	bool isWord(string s);
	
private:
	string clean_special();
	string clean_digit();
	string all_lower();
	Node* root;
	
}

#endif