//manager.cpp
//Created by: Cameron Barclift
//Manager class contains everything to run the simulation.

#include "manager.h"

////////////////PUBLIC METHODS///////////////////////

//Default constructor
Manager::Manager()
{
	absolute_time = 0;
}

//contains the time loop, and some testing lines while the program
//is under development
void Manager::run_floor()
{
	Order next_order;
	Queue order_out;
	
	//time loop
	//Exit Condition: The order_takers has no more orders in queue AND
	//the fetching unit is free (AND other things to be imlemented)
	while ((order_takers.is_done() == false) || (fetch_bot.unit_free() == false)){
		
		//if the fetcher is free, then give the fetcher the next order to arrive
		if(fetch_bot.unit_free()){
			fetch_bot.get_order(order_takers.pass_order());
		}
		
		/*DUBUG CODE
		//cout << "fetch_bot debug\n";
		//fetch_bot.print_debug();
		//cout << "fetch_bot order ready: " << fetch_bot.order_ready() << endl;
		DEBUG END*/
		
		
		//states that if the fetcher has fetched an order during this time step,
		//set the orders time out to the current time (this will be the time that
		//the left the system), then pass on the the order
		//to the next step.  Currently that step is just a print out queue in the manager,
		//it will eventually be the packing boss.
		if (fetch_bot.order_ready()){
			//cout << "check1\n";
			next_order = fetch_bot.deliver_order();
			next_order.t_out = absolute_time;
			order_out.insert(next_order);
		}
		
		/*DEBUG CODE
		//cout << "order_out queue\n";
		//order_out.print_queue();
		//cout << "order_takers.is_done: " << order_takers.is_done() << endl;
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free() << endl << endl;
		DEBUG END*/
		
		increment_time();
	};
	
	/*DEBUG CODE
	//cout << "order_takers queue: " << endl;
	//order_takers.print_buffer();
	//cout << "order_out Queue: " << endl;
	DEBUG END*/
	
	order_out.print_queue();
}

/////////PRIVATE METHODS///////////////

//Handles the time increment functions for manager and all
//member classes that contain time functions.
void Manager::increment_time()
{
	++absolute_time;
	order_takers.increment_time();
	fetch_bot.increment_time();
}
