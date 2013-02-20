//Sequence.cpp file for HW 2, defines
//the functions from sequence.h
//Created by: Cameron Barclift
//This program implements the sequence as a queue,
//elements are removed from the front and added to
//the back.

#include "sequence.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Default Constructor
Sequence_List::Sequence_List()
{
	head = NULL;
	tail = NULL;
}

//Checks if list is empty, returns true if it is empty
bool Sequence_List::Is_Empty()
{
	if(head == NULL){
		return true;
	}else {
		return false;
	}
}

//copy constructor
Sequence_List::Sequence_List(const Sequence_List &rhs)
{
	head = NULL;
	tail = NULL;
	//Calls a private function to copy the nodes
	copy_lists(rhs.head);
}

//Recursive function to copy the node from one list to a new list
void Sequence_List::copy_lists(Node* h_in)
{
	Node* copy_node = NULL;
	
	if (h_in == NULL){
		return;
	}else if (h_in != NULL){
		copy_node = new Node;
		//copy data into new node
		copy_node->data = h_in->data;
		
		//if the new list is empty, head and tail point to new node,
		//otherwise tail is moved to the next node
		if (Is_Empty()){
			head = copy_node;
			tail = copy_node;
		}else{
			tail->next = copy_node;
			tail = copy_node;
		}
		copy_lists(h_in->next);
	}
}

//new node added onto the tail of the linked list
//value is passed in.
void Sequence_List::insert(Element_Type value_in)
{
	//A new node is created, assigned the value passed,
	//and next is set to NULL
	Node* add_node = new Node;
	add_node->data = value_in;
	add_node->next = NULL;
	
	if (Sequence_List::Is_Empty()){
		//cerr << "adding, list empty.\n";//DEBUG CODE
		head = add_node;
		tail = add_node;
		return;
	}else if(!Sequence_List::Is_Empty()){
		//cerr << "adding, list NOT empty.\n";//DEBUG CODE
		tail->next = add_node;
		tail = add_node;
		return;
	}
}

//Removes an element from the front of a sequence.
//Remove cannot handle an empty list, it will exit 
//the program with an error
Element_Type Sequence_List::remove()
{
	Node* temp_node;
	Element_Type data_out;
	
	if(Sequence_List::Is_Empty()){
		//if list is empty, error message and exit
		cerr << "List empty, cannot remove.\n";
		exit(1);
	}else if(!Sequence_List::Is_Empty()){
		//temp_node assigned to head, then head moved to next node
		temp_node = head;
		head = head->next;
		data_out = temp_node->data;
		
		//deletes the node removed
		delete temp_node;
		return data_out;
	}
return 0;
}

//takes in a copy of a list, and removes all of the elements 
//and puts them into the sequence, using insert and remove
//list_in is a copy of the sequence passed to concatenation,
//and is destroyed by the function.  Sequence is passed by 
//value.
void Sequence_List::concatenation(Sequence_List list_in)
{	
	//loops until list_in is empty
	while (!list_in.Is_Empty()){
		insert(list_in.remove());
	}
}

//public print function, only calls priv_print to facillitiate recursion
void Sequence_List::print()
{
	priv_print(head);
}

//private print function, so I can do recusion and pass it head
//recusively prints all of the elements of a list and ends with an end-line
void Sequence_List::priv_print(Node* iter)
{
	if(iter == NULL){
		cout << endl;
		return;
	}else if (iter != NULL){
		cout << iter->data << " ";
		priv_print(iter->next);
	}
}

//default destructor
Sequence_List::~Sequence_List()
{
}
