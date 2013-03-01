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
	while ((order_takers.is_done() == false) || (fetch_bot.unit_free() == false)){
		//cout << "check1\n";
		if(fetch_bot.unit_free()){
			fetch_bot.get_order(order_takers.pass_order());
		}
		
		//cout << "fetch_bot debug\n";
		//fetch_bot.print_debug();
		//cout << "fetch_bot order ready: " << fetch_bot.order_ready() << endl;
		
		if (fetch_bot.order_ready()){
			//cout << "check1\n";
			next_order = fetch_bot.deliver_order();
			next_order.t_out = absolute_time;
			order_out.insert(next_order);
		}
		
		//cout << "order_out queue\n";
		//order_out.print_queue();
		
		//cout << "order_takers.is_done: " << order_takers.is_done() << endl;
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free() << endl << endl;
		
		increment_time();
	};
	
	//cout << "order_takers queue: " << endl;
	//order_takers.print_buffer();
	
	//cout << "order_out Queue: " << endl;
	order_out.print_queue();
}