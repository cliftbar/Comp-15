//front.cpp
//Created by: Cameron Barclift

#include "buffer.h"
////////////Public Methods///////////

Buffer::Buffer()
{
}

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
			
			order_queue.insert(new_order);
		}
	}
	
	

return;
}

bool Buffer::is_order()
{
	return true;
}

Queue Buffer::pass_queue()
{
	Queue pass_to = order_queue;
	
return pass_to;
}

void Buffer::print_orders()
{
	order_queue.print_queue();
}