//dictionary.h
//Created by: Cameron Barclift
//Class contains the functions neccessary for the operation of a dictionary
//using a trei data structure.  Allows for words to be stored, can print all
//words stored, and can look up whether a specific word is stored and if a
//specific string is a prefix of a word.  Dictionary contains only
//alphabetical characters; any characters that are not alphabetical are
//removed from the input string, which is then stored, even if it is empty

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
	//Default constructor
	Dictionary();
	//Adds a word to the dictionary, returns false if out of memory
	bool insert(string s);
	//returns true if the string passed in is a prefix of a word in the
	//dictionary (an entire word is a prefix of itself)
	bool isPrefix(string s);
	//returns true if the word is in the dictionary
	bool isWord(string s);
	//prints all words in the dictionary
	void print_all_words();
	
private:
	//takes in a string are returns the string with any non-alphabetical
	//characters removed
	string clean_word(string s_in);
	//returns the proper array element postion for the current character
	int alpharray_pos(char c_in);
	//recursive part of insert fuction
	bool rec_insert(Node* np_in);
	//recursive function to follow a path, used for both isPrefix and isWord
	bool rec_find_path(Node* np_in, bool prefix);
	//recursive part of print function
	void rec_print(Node* np_in, string print_string);
	//root of trei data structure
	Node* root;
	//current string passed in
	string s_curr;
	//current character postion in current string
	unsigned int curr_s_pos;
};

#endif