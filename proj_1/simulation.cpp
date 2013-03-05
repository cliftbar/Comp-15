//simulation.cpp
//Created by: Cameron Barclift
//Simulation class contains everything to run the simulation.

#include "simulation.h"

////////////////PUBLIC METHODS///////////////////////

//Default constructor
Simulation::Simulation(bool is_supreme, Queue* sales_queue)
{
	supreme = is_supreme;
	order_takers = new Front_Desk(supreme, sales_queue);
	calc_shop = new Stats(supreme);
	absolute_time = 0;
}

//contains the time loop, and some testing lines while the program
//is under development
void Simulation::run_sim()
{
	Order next_order;
	Queue order_out;
	//int num_packer_orders;//DEBUG CODE
	
	//time loop
	//Exit Condition: The order_takers has no more orders in queue AND
	//the fetching unit is free (AND other things to be imlemented)
	while (!order_takers->is_done() || !fetch_bot.unit_free() || !pack_chief.all_done()){
		
		//if the fetcher is free, then give the fetcher the next order to arrive
		if(fetch_bot.unit_free() && !order_takers->is_done()){
			//cout << "order takers is done: " << order_takers.is_done() << endl;//DEBUG CODE
			//cout << "fetch_bot print" << endl;//DEBUG CODE
			//fetch_bot.print_debug();//DEBUG CODE
			fetch_bot.get_order(order_takers->pass_order());
			//fetch_bot.print_debug();//DEBUG CODE
		}
		
		//cout << "order_out queue 1\n";//DEBUG CODE
		//order_out.print_queue();//DEBUG CODE
		
		//DUBUG CODE
		//cout << "fetch_bot debug\n";
		//fetch_bot.print_debug();
		//cout << "fetch_bot order ready: " << fetch_bot.order_ready() << endl;
		//DEBUG END
		
		
		//states that if the fetcher has fetched an order during this time step,
		//set the orders time out to the current time (this will be the time that
		//the left the system), then pass on the the order
		//to the next step.  Currently that step is just a print out queue in the manager,
		//it will eventually be the packing boss.
		if (fetch_bot.order_ready()){
			//cout << "check1\n";//DEBUG CODE
			pack_chief.pass_in(fetch_bot.deliver_order());
		}
		
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free() << endl;
		//pack_bot.print_current();//DEBUG CODE
		//cout << "regular current wait: " << pack_bot.wait_time(false) << endl << endl;//DEBUG CODE
		//cout << "supreme current wait: " << pack_bot.wait_time(true) << endl << endl;//DEBUG CODE
		//pack_bot.print_queue();
		
		//pack_chief.print_packers();//DEBUG CODE
		//cout << "check 9" << endl;//DEBUG
		//cout << "pack_chief.num_orders_up: " << pack_chief.num_orders_up() << endl;//DEBUG CODE
		while (pack_chief.num_orders_up() > 0){
			//cout << "check2\n";//DEBUG CODE
			next_order = pack_chief.pass_out();
			//cout << "next order id: " << next_order.id << endl;//DEBUG CODE
			next_order.t_out = absolute_time;
			calc_shop->get_order(next_order);
			calc_shop->run_calcs();
			next_order = calc_shop->return_order();
			if (!supreme){
				if(next_order.switched){
					next_order.priority = "supreme";
				}
			}
			//cout << "order inserted" << endl;//DEBUG CODE
			order_out.insert(next_order);
		}
		//cout << "pack_chief.all_done(): " << pack_chief.all_done() << endl << endl;//DEBUG CODE

			
		///*DEBUG CODE
		//cout << "order_out queue 2\n";//DEBUG CODE
		//order_out.print_queue();//DEBUG CODE
		//cout << "order_takers.is_done: " << order_takers.is_done() << endl;
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free() << endl << endl;
		//DEBUG END*/
		
		increment_time();
	};
	
	/*DEBUG CODE
	//cout << "order_takers queue: " << endl;
	//order_takers.print_buffer();
	//cout << "order_out Queue: " << endl;
	DEBUG END*/
	
	//cout << "check15\n";//DEBUG CODE
	
	//cout << "check14\n";//DEBUG CODE
	/*
	while (!order_out.is_empty()){
		calc_shop->get_order(order_out.remove());
		//cout << "check13\n";//DEBUG CODE
		calc_shop->run_calcs();
	}
	*/
	order_out.print_queue();
	//cout << "check12\n";//DEBUG CODE
	calc_shop->print_stats();	
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
