//Header file for Comp-15 HW 2
//Created by: Cameron Barclift
//Declares a class to contain a sequence and relavent
//functions and a node struct for a linked list implementation

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>

//declares a typedef Element_Type
typedef int Element_Type;

using namespace std;

//Node declaration
struct Node
{
	Element_Type data;
	Node* next;
};

class Sequence_List
{
	public:
		//constructor
		Sequence_List();
		
		//copy constructor
		Sequence_List(const Sequence_List &rhs);
		
		//returns true if the list is empty
		bool Is_Empty();
		
		//inserts the passed value into the list
		void insert(Element_Type value_in);
				
		void concatenation(const Sequence_List list_in);
		
		Element_Type remove();
		
		void print();
		
		//Destructor
		~Sequence_List();
		
	private:
		Node* head;
		Node* tail;
		
		//private print function, so I can get to head
		void priv_print(Node* iter);
		
		//copies the list given into a new list for copy contructor
		void copy_lists(Node* h_in);
};

#endif
