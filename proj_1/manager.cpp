//manager.cpp
#include "manager.h"
Manager::Manager()
{
	absolute_time = 0;
}

void Manager::increment_time()
{
	++absolute_time;
}

void Manager::run_floor()
{
	Buffer sales;
	Order next_order;
	Queue order_out;
	
	sales.read_in();
	sales.print_orders();
	
	order_queue = sales.pass_queue();
	
	while (!order_queue.is_empty()){
		if (order_queue.t_next() == absolute_time){
			next_order = order_queue.remove();
			next_order.t_out = absolute_time;
			order_out.insert(next_order);
		}
		increment_time();
	}
	
	order_queue.print_queue();
	order_out.print_queue();
}