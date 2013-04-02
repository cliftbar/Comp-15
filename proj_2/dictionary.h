//dictionary.h

#ifndef DICTIONARY
#define DICTIONARY
#include "node.h"
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
	void print_all_words();
	
private:
	string clean_word(string s_in);
	int alpharray_pos(char c_in);
	void rec_insert(Node* np_in);
	bool rec_string_find(Node* np_in, bool prefix);
	void rec_print(Node* np_in, string print_string);
	Node* root;
	string s_curr;
	unsigned int curr_s_pos;
};

#endif