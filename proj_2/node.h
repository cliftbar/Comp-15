//node.h
//Created by: Cameron Barclift
//Node class for dictionary.  The length of the array is set to 26 characters 
//(the length of the alphabet).  array_access() and make_node() allow indirect 
//access to the array, and set_word_here() and word_here() allow indirect
//access to is_word.  

#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
	//Default Constructor
	Node();
	//returns the pointer contained at the designated position in the array
	Node* array_access(int pos);
	//uses the new operator to make a new node for the indicated position in
	//the array
	void make_node(int pos);
	//returns the state of is_word
	bool word_here();
	//sets is_word to the values passed in
	void set_word_here(bool setter);
	
private:
	//static array of pointers to node, containing 26 elements that represent
	//alphanumeric characters.  Trei implementation
	Node* alpharray[26];
	//True if the node is the end of a path representing a word.
	bool is_word;
};

#endif
	