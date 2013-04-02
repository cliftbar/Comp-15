//node.h

#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>
using namespace std;

class Node
{
public:
	Node();
	//insert(string str_insert);
	Node* alpharray[26];
	bool word_here();
	void set_word_here(bool setter);
	
private:
	bool is_word;
	int ALPHA_LENGTH;
};

#endif
	