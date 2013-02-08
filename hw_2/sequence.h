#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>
typedef int Element_Type;

using namespace std;

struct Node
{
	ElementType data;
	Node* next;
};

class Sequence_List
{
	Public:
		//constructor
		Sequence_List();
		
		//copy constructor
		Sequence_List(Sequence_List &rhs);
		
		//returns true if the list is empty
		bool isEmpty();
		
		//inserts the passed value into the list
		void insert(Element_Type value_in);
				
		void concatenation();
		
		void remove();
		
		//Destructor
		~Sequence_List();
		
	Private:
		Node* head;
		Node* tail;
};



#endif
