
#include "sequence.h"
#include <iostream>

using namespace std;

Sequence_List::Sequence_List()
{
	head = NULL;
	tail = NULL;
}

Sequence_List::Is_Empty()
{
	if(head == NULL){
		return true;
	}else {
		return false;
	}
}

//new node added onto the end of the linked list
Sequence_List::insert(Element_Type value_in)
{
	Node* node_in = new Node;
	node_in->data = value_in
	node_in->next = NULL;
	
	if (Is_Empty){
		head = node_in;
		tail = node_in
		return;
	}else if(Is_Empty != false){
		tail->next = node_in;
		tail = node_in;
}

Sequence_List::concatentation(Sequence_List* list_in)
{
	
}

Sequence_List::remove();
{
	
}