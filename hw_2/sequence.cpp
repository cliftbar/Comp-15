
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

//copy constructor
Sequence_List::Sequence_List(const Sequence_List &rhs)
{
	head = NULL;
	copy_lists(rhs.head);
}

void Sequence_List::copy_lists(Node* h_in)
{
	Node* copy_node = NULL;
	
	if (h_in == NULL){
		return;
	}else if (h_in != NULL){
		copy_node = new Node;
		copy_node->data = h_in->data;
		copy_node->next = h_in->next;
		if (head == NULL){
		head = copy_node;
		}
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

void Sequence_List::concatenation(const Sequence_List list_in)
{
	Sequence_List list_in_copy = list_in;
	
	while (!list_in_copy.Is_Empty()){
		insert(list_in_copy.remove());
	}	
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




