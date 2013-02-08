
#include "sequence.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Sequence_List::Sequence_List()
{
	head = NULL;
	tail = NULL;
}

bool Sequence_List::Is_Empty()
{
	if(head == NULL){
		return true;
	}else {
		return false;
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
		add_node->next = head;
		head = add_node;
		return;
	}
}

int Sequence_List::remove()
{
	Node* node_out;
	
	if(Sequence_List::Is_Empty()){
		//cerr << "list empty, no remove.\n";//DEBUG CODE
		exit(1);
	}else if(!Sequence_List::Is_Empty()){
		node_out = head;
		head = head->next;
		return node_out->data;
	}
	
return 0;
}

void Sequence_List::concatenation(Sequence_List list_in)
{
	Node* list_in_copy = NULL;
	Node* current_list = head;
	
	//list_in_copy = list_in //make copy constructor work here
	
	//tail points to last element
	//list_in_copy is the head of a dynamic list
	//tail->next = list_in_copy;
	
}

//public print function, just calls priv_print
void Sequence_List::print()
{
	priv_print(head);
}

//private print function, so I can do recusion and pass it head
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




