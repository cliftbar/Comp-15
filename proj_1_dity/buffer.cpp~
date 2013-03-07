//buffer.cpp
//Created by: Cameron Barclift
//need a destructor
//Buffer reads input from the standard stream and stores the relevant
//data into a queue.  It can pass out a copy of the buffer queue

#include "buffer.h"

////////////Public Methods///////////

//constructor
Buffer::Buffer()
{
	//default constructor
}

//reads in and stores the file/stream input into a queue
void Buffer::read_in()
{
	string junk;
	Order new_order;

	while(!cin.eof()){
		//read in to check if we're still in the stream
		cin >> junk;
		if(!cin.eof()){
			//read in data
			cin >> new_order.id;
			cin >> junk;
			cin >> new_order.priority;
			cin >> junk >> junk >> junk >> junk;
			cin >> new_order.t_arrive;
			cin >> junk >> junk;
			cin >> new_order.t_fetch;
			cin >> junk >> junk >> junk;
			cin >> new_order.t_pack;
			cin >> junk;
			
			//initialize order parameters
			new_order.t_out_sim1 = 0;
			new_order.t_out_sim2 = 0;
			new_order.fetch_wait = 0;
			new_order.front_wait = 0;
			new_order.pack_wait = 0;
			new_order.spent_interrupted = 0;
			new_order.switched = false;

			order_queue.insert(new_order);
		}
	}
	
return;
}

//returns a pointer to a copy of the buffer queue
Queue* Buffer::pass_queue()
{
	//Order hold_order;
	Queue* pass_to = new Queue;
	Queue temp = order_queue;
	
	//copies temp queue to new dynamic array
	while(!temp.is_empty()){
		pass_to->insert(temp.remove());
	}
	
return pass_to;
}

void Buffer::print_orders()
{
	order_queue.print_queue();
}
