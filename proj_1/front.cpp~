//front.cpp
//Created by: Cameron Barclift
//Front_Desk class acts as the order reciever from an input buffer,
//class never actually directly reads from the stream or a file.

#include "front.h"

////////////////PUBLIC METHODS///////////////////////

//default constructor, sets initial values AND reads in the buffer,
//make sure you want that when you create this class.
Front_Desk::Front_Desk()
{
	desk_time = 0;
	done = false;
	buffer_queue = NULL;
	run_buffer();
}

//true: done, queue empty
//false: not done, queue not empty
bool Front_Desk::is_done()
{
	//cout << "buffer queue empty: " << buffer_queue->is_empty() << endl;??DEBUG CODE
	
	return done;
}


//For manager use ONLY!!!!!!!
void Front_Desk::increment_time()
{
	++desk_time;
}

//passes the next order out of the class, then adds a new order to the
//internal next order slot.  If the queue is empty, done is set to true
Order Front_Desk::pass_order()
{
	Order r_order = next_order;
	
	//check if queue is empty
	if (!buffer_queue->is_empty()){
		next_order = buffer_queue->remove();
	}else if (buffer_queue->is_empty()){
		done = true;
	}
	
	//sets the fetch_wait to the time spent waiting to be fetched
	r_order.front_wait = desk_time;
	
	//cout << "pass_order id: " << r_order.id << endl;//DEBUG CODE
	
	return r_order;
}

void Front_Desk::print_buffer()
{
	buffer_queue->print_queue();
}

/////////PRIVATE METHODS///////////////


//Creates an instance of the buffer class, reads in the input using the buffer,|||||
//then stores the buffer queue (a dynamic linked list).  If the buffer is not
//empty, the first order is removed from the internal queue and stored.
void Front_Desk::run_buffer()
{
	Buffer sales;
	
	sales.read_in();
	
	//sales.print_orders();//DUBUG CODE
	
	buffer_queue = sales.pass_queue();
	
	if (!buffer_queue->is_empty()){
		next_order = buffer_queue->remove();
	}
}
