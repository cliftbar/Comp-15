//node.h
//Created by: Cameron Barclift
//Node class for dictionary.  The length of the array is set to 26 characters 
//(the length of the alphabet).  array_access() and make_node() allow indirect 
//access to the array, and set_word_here() and word_here() allow indirect
//access to is_word.  

#include "node.h"

/////////////////////////////Public Methods///////////////////////////////////

//Default constructor, intializes every element of the array to NULL, sets
//is_word to false
Node::Node()
{
	for (int i = 0; i < 26; ++i){
		alpharray[i] = NULL;
	}
	
	is_word = false;
}

//Returns the pointer contained in the array at the position passed in
Node* Node::array_access(int pos)
{
	return alpharray[pos];
}

//makes a new node and stores the address in the array
void Node::make_node(int pos)
{
	alpharray[pos] = new Node;
}

//Returns the value of is_word
bool Node::word_here()
{
	return is_word;
}

//Sets the value of is_word to the value passed in
void Node::set_word_here(bool setter)
{
	is_word = setter;
}

