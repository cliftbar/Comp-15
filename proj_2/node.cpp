//node.cpp

#include "node.h"

/////////////////////////////Public Methods///////////////////////////////////
Node::Node()
{
	ALPHA_LENGTH = 26;
	for (int i = 0; i < ALPHA_LENGTH; ++i){
		alpharray[i] = NULL;
	}
	
	is_word = false;
}

bool Node::word_here()
{
	return is_word;
}

void Node::set_word_here(bool setter)
{
	is_word = setter;
}

//Node::insert(string str_insert){
