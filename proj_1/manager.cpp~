//manager.cpp
#include "manager.h"
Manager::Manager()
{
	absolute_time = 0;
}

void Manager::increment_time()
{
	++absolute_time;
	order_takers.increment_time();
	fetch_bot.increment_time();
}

void Manager::run_floor()
{
	Order next_order;
	Queue order_out;
	
	//time loop
	do{
		if(fetch_bot.unit_free()){
			fetch_bot.get_order(order_takers.pass_order());
		}
		
		//fetch_bot.print_debug();
		//cout << "fetch_bot order ready: " << fetch_bot.order_ready() << endl;
		if (fetch_bot.order_ready()){
			//cout << "check1\n";
			next_order = fetch_bot.deliver_order();
			next_order.t_out = absolute_time;
			order_out.insert(next_order);
		}
		increment_time();
	}while (!order_takers.is_done() && !fetch_bot.unit_free());
	
	order_takers.print_buffer();
	order_out.print_queue();
}