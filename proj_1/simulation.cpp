//simulation.cpp
//Created by: Cameron Barclift
//Simulation class contains everything to run the simulation.

#include "simulation.h"

////////////////PUBLIC METHODS///////////////////////

//Preferred constructor
Simulation::Simulation(bool is_supreme, Queue* sales_queue)
{
	supreme = is_supreme;
	
	//initializes Front_Desk class with whether to consider supreme orders,
	//and gives it a copy of the input buffer
	order_takers = new Front_Desk(supreme, sales_queue);
	
	//initializes Stats class variable with whether
	//to consider supreme orders
	calc_shop = new Stats(supreme);
	absolute_time = 0;
}

//function to handle running the simulation
Queue* Simulation::run_sim()
{
	order_out = new Queue;
	
	//time loop
	//Exit Condition: The order_takers has no more orders in queue AND
	//the fetching unit is free AND the packing unit is done)
	while (!order_takers->is_done() || !fetch_bot.unit_free() ||
		  !pack_chief.all_done()){
		
		pack_chief_loop();
		
		fetch_bot_loop();
		
		order_takers_loop();
		
		increment_time();
	};
	
	return order_out;
}

/////////PRIVATE METHODS///////////////

//Handles the time increment functions for manager and all
//member classes that contain time functions.
void Simulation::increment_time()
{
	++absolute_time;
	order_takers->increment_time();
	fetch_bot.increment_time();
	pack_chief.increment_time();
}

void Simulation::un_switch()
{
	if (!supreme){
		if(next_order.switched){
			next_order.priority = "supreme";
		}
	}
}

//if the pack_chief has an order ready, the pack_chief passes
//the order to a hold variable, the hold variable stores the time
//that it was passed out by the packers.
//The order is then passed to the output queue to be printed at
//the end of the simulation
void Simulation::pack_chief_loop()
{
	while (pack_chief.num_orders_up() > 0){
		next_order = pack_chief.pass_out();
		
		//sets time out of simulation based on whether simulation
		//is considering supreme orders or not
		if (!supreme){
			next_order.t_out_sim1 = absolute_time - next_order.t_arrive;
		}else if (supreme) {
			next_order.t_out_sim2 = absolute_time - next_order.t_arrive;
		}
		
		//if the simulation is not considering supreme orders, the 
		//orders that had their priority altered are returned to 
		//their original state for printing and calculations
		un_switch();
		
		//put into output queue
		order_out->insert(next_order);
	}
}

//states that if the fetcher has fetched an order
//during this time step, then pass on the the order
//to the pack_bot, which handles the packing
void Simulation::fetch_bot_loop()
{
	if (fetch_bot.order_ready()){
		pack_chief.pass_in(fetch_bot.deliver_order());
	}
}

//if the fetcher is free, an order has arrived, and the front desk queue
//is not empty, the front desk passes the next order in line to the fetcher
void Simulation::order_takers_loop()
{
	if(fetch_bot.unit_free() && !order_takers->is_done()
						&& order_takers->has_arrived()){
		
		fetch_bot.get_order(order_takers->pass_order());
	}
}
