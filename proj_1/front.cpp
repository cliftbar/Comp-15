//front.cpp
//Created by: Cameron Barclift
//Front_Desk class acts as the order reciever from an input buffer,
//class never actually directly reads from the stream or a file.

#include "front.h"

////////////////PUBLIC METHODS///////////////////////

//preferred constructor, initializes whether to consider supreme orders
//and copies the queue passed into the class
Front_Desk::Front_Desk(bool do_supreme, Queue* queue_in)
{
	consider_supreme = do_supreme;
	desk_time = 0;
	done = false;
	//copies the queue passed in
	run_buffer(queue_in);
}

//true: done, queue empty
//false: not done, queue not empty
bool Front_Desk::is_done()
{
	//cout << "buffer queue empty: " << buffer_queue->is_empty()
		  //<< endl;//DEBUG CODE
	
	return done;
}

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

	//If supreme is not being considered, and the priority of the order
	//is supreme, then the priority is changed from supreme to regular
	//and the switched variable is set to true to note the change
	if (!consider_supreme){
		if(r_order.priority == "supreme"){
			r_order.priority = "regular";
			r_order.switched = true;
		}
	}
	//cout << "pass_order id: " << r_order.id << endl;//DEBUG CODE
	
	return r_order;
}

void Front_Desk::print_buffer()
{
	buffer_queue->print_queue();
}

/////////PRIVATE METHODS///////////////


//Copies the buffer (the queue passed in) into the internal queue.
//If the buffer is not empty, the first order is removed from the
//internal queue and stored.
void Front_Desk::run_buffer(Queue* queue_in)
{
		
	buffer_queue = queue_in;
	
	//stores first order in next order slot if the queue isn't empty
	if (!buffer_queue->is_empty()){
		next_order = buffer_queue->remove();
	}
}
