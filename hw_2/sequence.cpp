
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
	tail = NULL;
	copy_lists(rhs.head);
}

void Sequence_List::copy_lists(Node* h_in)
{

	Node* copy_node = NULL;
	
	if (h_in != NULL){
		//cout << "head_in: " << h_in->data << endl;
	}else{
		//cout << "h_in NULL\n";
	}
	
	if (h_in == NULL){
		//cout << "tail->data: " << tail->data << endl;
		tail = NULL;
		return;
	}else if (h_in != NULL){
		copy_node = new Node;
		//cout << "check2\n";	
		copy_node->data = h_in->data;
		
		if (Is_Empty()){
			//cout << "head == NULL\n";
			head = copy_node;
			tail = copy_node;
		}else{

		//cout << "check1\n";
		tail->next = copy_node;
		
		//cout << "check3\n";	
		tail = copy_node;
		
		}
		//cout << "head->data: " << head->data << endl;
		//cout << "copy_node->data: " << copy_node->data << endl;
		copy_lists(h_in->next);

	}
}

//new node added onto the end of the linked list
//This is not implemented yet!!!!!!!!!!!!!!
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

Element_Type Sequence_List::remove()
{
	Node* node_out;
	
	if(Sequence_List::Is_Empty()){
		cerr << "list empty, no remove.\n";//DEBUG CODE
		exit(1);
	}else if(head == NULL){
		node_out = head;
		head = NULL;
		tail = NULL;
	}else if(!Sequence_List::Is_Empty()){
		node_out = head;
		head = head->next;
		return node_out->data;
	}
	
return 0;
}

void Sequence_List::concatenation(Sequence_List list_in)
{
	//cout << "list_in_copy = list_in\n";
	//Sequence_List list_in_copy = list_in;
	
	//cout << "list_in_copy\n";
	//list_in_copy.print();
	
	while (!list_in.Is_Empty()){
		//cout << "list_in_copy\n";
		//cout << "list_in print: ";
		//list_in.print();
		insert(list_in.remove());
		//cout << "print: ";
		//print();
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




