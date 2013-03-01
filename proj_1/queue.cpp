//queue.cpp
//Created by: Cameron Barclift
//implements a queue of orders, fifo

#include "queue.h"

////////////////PUBLIC METHODS///////////////////////

//default constructor
Queue::Queue()
{
	front = NULL;
	back = NULL;
	length = 0;
}

//copy constructor
Queue::Queue(const Queue &rhs)
{
	front = NULL;
	back = NULL;
	length = 0;
	
	copy_in_list(rhs.front);
}

bool Queue::is_empty()
{
	return (front == NULL);
}

//inserts an order, original order is perserved
void Queue::insert(const Order to_add)
{
	Node* temp = new Node;
	temp->data = to_add;
	temp->next = NULL;
	
	if (is_empty()){
		front = temp;
		back = temp;
	}else {
		back->next = temp;
		back = back->next;
	}
	
	++length;
	
return;
}

//cannot handle an empty functions
//destroys dynamic node in queue
Order Queue::remove()
{
	Node* temp;
	Order r_var;
	
	if (is_empty()){
		cerr << "queue empty, failure.\n";
		exit(1);
	}
	
	temp = front;
	front = front->next;
	
	r_var = temp->data;
	delete temp;
	
	--length;
	
return r_var;
}

int Queue::get_length()
{
	return length;
}

void Queue::print_queue()
{
	Node* iter = front;
	
	while(iter != NULL){
		cout << "Order " << iter->data.id << " ";
		cout << "for " << iter->data.priority << " customer ";
		cout << "arrived at time " << iter->data.t_arrive << endl;
		cout << "fetch time " << iter->data.t_fetch << " minutes, ";
		cout << "pack time " << iter->data.t_pack << " minutes" << endl;
		
		cout << "the order was added to packaging queue at time " << iter->data.fetch_wait << endl;
		//cout << "Time out: " << iter->data.t_out << endl;
		cout << endl;
		
		iter = iter->next;
	}
	
	//cout << "queue length: " << length << endl << endl;//DEBUG
}

//returns the arrival time of the next order in the queue
int Queue::t_next()
{
	return front->data.t_arrive;
}

/////////PRIVATE METHODS///////////////

//Deletes the entire list
void Queue::delete_list()
{
	Node* temp;
	Node* iter = front;
	
	while(iter != NULL){
		temp  = iter;
		iter = iter->next;
		delete temp;
	}
	
	front = NULL;
	back = NULL;
}

//copies a queue into this queue
void Queue::copy_in_list(Node* f_other)
{
	Node* f_in = f_other;
	
	while(f_in != NULL){
		insert(f_in->data);
		f_in = f_in->next;
	}
}
