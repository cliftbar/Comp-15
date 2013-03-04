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
}

//reads in and stores the file/stream input into a queue
void Buffer::read_in()
{
	string junk;
	Order new_order;

	while(!cin.eof()){
		cin >> junk;
		if(!cin.eof()){
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
			
			new_order.t_out = 0;
			new_order.fetch_wait = 0;

			order_queue.insert(new_order);
		}
	}
	
return;
}

//returns a pointer to a copy of the buffer queue
Queue* Buffer::pass_queue()
{
	Queue* pass_to = new Queue;
	Queue temp = order_queue;
	
	while(!temp.is_empty()){
		pass_to->insert(temp.remove());
	}
	
return pass_to;
}

void Buffer::print_orders()
{
	order_queue.print_queue();
}