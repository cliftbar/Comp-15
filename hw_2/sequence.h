//Header file for Comp-15 HW 2
//Created by: Cameron Barclift
//Declares a class to contain a sequence and relavent
//functions and a node struct for a linked list implementation.
//This program implements the sequence as a queue,
//elements are removed from the front and added to
//the back.  This implementation allowed for concatenate to call
//insert and remove while perserving the order of the two sequences.

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>
using namespace std;
//declares a typedef Element_Type
typedef int Element_Type;

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
		
		//adds one sequence onto another. 
		//The order of the added sequence is perserved,
		//and the added sequence is not altered
		void concatenation(const Sequence_List list_in);
		
		//removes an element from a sequenece, returns the value of the element
		Element_Type remove();
		
		//prints all of the elements in a list, followed by an end line
		void print();
		
		//Destructor
		~Sequence_List();
		
	private:
		Node* head;
		Node* tail;
		
		//private print function, so I can get to head
		void priv_print(Node* iter);
		
		//copies the list given by the pointer into a new list for copy contructor
		void copy_lists(Node* h_in);
};

#endif
