//queue.cpp
//implements a queue, fifo

#include "queue.h"

///////////public functions///////////


Queue::Queue()
{
	front = NULL;
	back = NULL;
	length = 0;
}

Queue::Queue(const Queue &rhs)
{
	Node* f_in = rhs.front;
	front = NULL;
	back = NULL;
	length = 0;
	
	while(f_in != NULL){
		insert(f_in->data);
		f_in = f_in->next;
	}
}

bool Queue::is_empty()
{
	return (front == NULL);
}

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
		cout << "Order ID: " << iter->data.id << endl;
		cout << "Time arrive: " << iter->data.t_arrive << endl;
		cout << "Fetch Time: " << iter->data.t_fetch << endl;
		cout << "Packing Time: " << iter->data.t_pack << endl;
		cout << "Priority: " << iter->data.priority << endl;
		cout << "Time out: " << iter->data.t_out << endl;
		cout << endl;
		
		iter = iter->next;
	}
	
	cout << "queue length: " << length << endl << endl;
}

int Queue::t_next()
{
	return front->data.t_arrive;
}