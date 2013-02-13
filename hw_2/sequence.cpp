//Sequence.cpp file for HW 2, defines
//the functions from sequence.h
//Created by: Cameron Barclift

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

//Checks if list is empty
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
	
	/*/////DEBUG CODE////////
	if (h_in != NULL){
		//cout << "head_in: " << h_in->data << endl;
	}else{
		//cout << "h_in NULL\n";
	}
	//////DEBUG END////////*/
	
	if (h_in == NULL){
		//!!Check if I need to set tail == NULL
		//cout << "tail->data: " << tail->data << endl;//DEBUG CODE
		tail = NULL;
		return;
	}else if (h_in != NULL){
		copy_node = new Node;
		//cout << "check2\n";//DEBUG CODE
		//copy data into new node
		copy_node->data = h_in->data;
		
		//if the new list is empty, head and tail point to new node,
		//otherwise tail is moved to the next node
		if (Is_Empty()){
			//cout << "head == NULL\n";//DEBUG CODE
			head = copy_node;
			tail = copy_node;
		}else{
		//cout << "check1\n";//DEBUG CODE
		tail->next = copy_node;
		//cout << "check3\n";//DEBUG CODE	
		tail = copy_node;
		}
		//cout << "head->data: " << head->data << endl;//DEBUG CODE
		//cout << "copy_node->data: " << copy_node->data << endl;//DEBUG CODE
		copy_lists(h_in->next);
	}
}

//new node added onto the end of the linked list
void Sequence_List::insert(Element_Type value_in)
{
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
	Node* node_out;
	Element_Type data_out;
	
	if(Sequence_List::Is_Empty()){
		//if list is empty, error message and exit
		cerr << "list empty, no remove.\n";//DEBUG CODE
		exit(1);
	}else if(head == NULL){
		//!!check if this is needed
		node_out = head;
		head = NULL;
		tail = NULL;
	}else if(!Sequence_List::Is_Empty()){
		node_out = head;
		head = head->next;
		data_out = node_out->data;
		delete node_out;//!!made a change here
		return data_out;
	}
return 0;
}

//takes in a copy of a list, and removes all of the elements 
//and puts them into the sequence, using insert and remove
void Sequence_List::concatenation(Sequence_List list_in)
{
	//cout << "list_in_copy = list_in\n";//DEBUG CODE
	//Sequence_List list_in_copy = list_in;//DEBUG CODE
	
	//cout << "list_in_copy\n";//DEBUG CODE
	//list_in_copy.print();//DEBUG CODE
	
	while (!list_in.Is_Empty()){
		//cout << "list_in_copy\n";//DEBUG CODE
		//cout << "list_in print: ";//DEBUG CODE
		//list_in.print();//DEBUG CODE
		insert(list_in.remove());
		//cout << "print: ";//DEBUG CODE
		//print();//DEBUG CODE
	}
}

//public print function, just calls priv_print to facillitiate recursion
void Sequence_List::print()
{
	priv_print(head);
}

//private print function, so I can do recusion and pass it head
//prints all of the elements of a list and ends with an end-line
void Sequence_List::priv_print(Node* iter)
{
	if(iter == NULL){
		cout << endl;
		return;
	}else if (iter != NULL){
		cout << iter->data << " ";
		priv_print(iter->next);
	}
	
return;
}

//default destructor
Sequence_List::~Sequence_List()
{
	
}




