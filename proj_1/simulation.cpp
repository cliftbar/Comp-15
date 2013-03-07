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
/*
//function to handle running the simulation
Queue* Simulation::run_sim()
{
	Order next_order;
	Queue* order_out = new Queue;
	//int num_packer_orders;//DEBUG CODE
	
	//time loop
	//Exit Condition: The order_takers has no more orders in queue AND
	//the fetching unit is free AND the packing unit is done)
	while (!order_takers->is_done() || !fetch_bot.unit_free() ||
		  !pack_chief.all_done()){
		
		//if the fetcher is free, then give the fetcher
		//the next order to arrive
		if(fetch_bot.unit_free() && !order_takers->is_done()){
			//cout << "order takers is done: " << order_takers.is_done()
			       //<< endl;//DEBUG CODE
			       
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
		//cout << "fetch_bot order ready: "
			  //<< fetch_bot.order_ready() << endl;
		//DEBUG END
		
		
		//states that if the fetcher has fetched an order
		//during this time step, then pass on the the order
		//to the pack_bot, which handles the packing
		if (fetch_bot.order_ready()){
			//cout << "check1\n";//DEBUG CODE
			pack_chief.pass_in(fetch_bot.deliver_order());
		}
		
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free()
			  //<< endl;
		//pack_bot.print_current();//DEBUG CODE
		//cout << "regular current wait: " << pack_bot.wait_time(false)
			  //<< endl << endl;//DEBUG CODE
		//cout << "supreme current wait: " << pack_bot.wait_time(true)
			  //<< endl << endl;//DEBUG CODE
		//pack_bot.print_queue();
		
		//pack_chief.print_packers();//DEBUG CODE
		//cout << "check 9" << endl;//DEBUG
		//cout << "pack_chief.num_orders_up: " << pack_chief.num_orders_up()
			  //<< endl;//DEBUG CODE
		
		//if the pack_chief has an order ready, the pack_chief passes
		//the order to a hold variable, the hold variable stores the time
		//that it was passed out by the packers, then gets sent to
		//the Stats class, which runs the required calculations.  The order
		//is then passed to the output queue to be printed at the end of the
		//simulation
		while (pack_chief.num_orders_up() > 0){
			//cout << "check2\n";//DEBUG CODE
			next_order = pack_chief.pass_out();
			//cout << "next order id: " << next_order.id << endl;//DEBUG
			
			//sets time out of simulation based on whether simulation
			//is considering supreme orders or not
			if (!supreme){
				next_order.t_out_sim1 = absolute_time;
			}else if (supreme) {
				next_order.t_out_sim2 = absolute_time;
			}
			calc_shop->get_order(next_order);
			calc_shop->run_calcs();
			next_order = calc_shop->return_order();
			
			//if the simulation is not considering supreme orders, the 
			//orders that had their priority altered are returned to 
			//their original state for printing and calculations
			if (!supreme){
				if(next_order.switched){
					next_order.priority = "supreme";
				}
			}
			//cout << "order inserted" << endl;//DEBUG CODE
			order_out->insert(next_order);
		}
		//cout << "pack_chief.all_done(): " << pack_chief.all_done()
			  //<< endl << endl;//DEBUG CODE

			
		//*DEBUG CODE
		//cout << "order_out queue 2\n";//DEBUG CODE
		//order_out.print_queue();//DEBUG CODE
		//cout << "order_takers.is_done: " << order_takers.is_done()
			  //<< endl;
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free()
			  //<< endl << endl;
		//DEBUG END
		
		//increments the time at the end of each time loop iteration
		increment_time();
	};
	
	//DEBUG CODE
	//cout << "order_takers queue: " << endl;
	//order_takers.print_buffer();
	//cout << "order_out Queue: " << endl;
	//DEBUG END
	
	//cout << "check15\n";//DEBUG CODE
	
	//cout << "check14\n";//DEBUG CODE
	
	while (!order_out.is_empty()){
		calc_shop->get_order(order_out.remove());
		//cout << "check13\n";//DEBUG CODE
		calc_shop->run_calcs();
	}
	
	
	//prints output queue
	order_out->print_queue();
	//cout << "check12\n";//DEBUG CODE
	
	//prints calculation results
	calc_shop->print_stats();
	
	cout << "simulation done\n";
	return order_out;
}*/

//function to handle running the simulation, reverse test
Queue* Simulation::run_sim()
{
	Order next_order;
	Queue* order_out = new Queue;
	//int num_packer_orders;//DEBUG CODE
	
	//time loop
	//Exit Condition: The order_takers has no more orders in queue AND
	//the fetching unit is free AND the packing unit is done)
	while (!order_takers->is_done() || !fetch_bot.unit_free() ||
		  !pack_chief.all_done()){
		
		//if the pack_chief has an order ready, the pack_chief passes
		//the order to a hold variable, the hold variable stores the time
		//that it was passed out by the packers, then gets sent to
		//the Stats class, which runs the required calculations.  The order
		//is then passed to the output queue to be printed at the end of the
		//simulation
		while (pack_chief.num_orders_up() > 0){
			//cout << "check2\n";//DEBUG CODE
			next_order = pack_chief.pass_out();
			//cout << "next order id: " << next_order.id << endl;//DEBUG
			
			//sets time out of simulation based on whether simulation
			//is considering supreme orders or not
			if (!supreme){
				next_order.t_out_sim1 = absolute_time - next_order.t_arrive;
			}else if (supreme) {
				next_order.t_out_sim2 = absolute_time - next_order.t_arrive;
			}
			calc_shop->get_order(next_order);
			calc_shop->run_calcs();
			next_order = calc_shop->return_order();
			
			//if the simulation is not considering supreme orders, the 
			//orders that had their priority altered are returned to 
			//their original state for printing and calculations
			if (!supreme){
				if(next_order.switched){
					next_order.priority = "supreme";
				}
			}
			//cout << "order inserted" << endl;//DEBUG CODE
			order_out->insert(next_order);
		}
		
		
		
		//states that if the fetcher has fetched an order
		//during this time step, then pass on the the order
		//to the pack_bot, which handles the packing
		if (fetch_bot.order_ready()){
			//cout << "check1\n";//DEBUG CODE
			pack_chief.pass_in(fetch_bot.deliver_order());
		}
		
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free()
			  //<< endl;
		cout << "Packer wait times: " << endl;
		pack_chief.print_packers();//DEBUG CODE
		//cout << "regular current wait: " << pack_bot.wait_time(false)
			  //<< endl << endl;//DEBUG CODE
		//cout << "supreme current wait: " << pack_bot.wait_time(true)
			  //<< endl << endl;//DEBUG CODE
		//pack_bot.print_queue();
		
		//pack_chief.print_packers();//DEBUG CODE
		//cout << "check 9" << endl;//DEBUG
		//cout << "pack_chief.num_orders_up: " << pack_chief.num_orders_up()
			  //<< endl;//DEBUG CODE
		
		
		//cout << "pack_chief.all_done(): " << pack_chief.all_done()
			  //<< endl << endl;//DEBUG CODE

		//if the fetcher is free, then give the fetcher
		//the next order to arrive
		if(fetch_bot.unit_free() && !order_takers->is_done()){
			//cout << "order takers is done: " << order_takers.is_done()
			       //<< endl;//DEBUG CODE
			       
			cout << "fetch_bot print pre_get" << endl;//DEBUG CODE
			fetch_bot.print_debug();//DEBUG CODE
			fetch_bot.get_order(order_takers->pass_order());
			cout << "fetch_bot print post_get" << endl;//DEBUG CODE
			fetch_bot.print_debug();//DEBUG CODE
			cout << "Absolute time: " << absolute_time << endl;//DEBUG
		}
		
		//cout << "order_out queue 1\n";//DEBUG CODE
		//order_out.print_queue();//DEBUG CODE
		
		//DUBUG CODE
		//cout << "fetch_bot debug\n";
		//fetch_bot.print_debug();
		//cout << "fetch_bot order ready: "
			  //<< fetch_bot.order_ready() << endl;
		//DEBUG END
		
			
		//*DEBUG CODE
		//cout << "order_out queue 2\n";//DEBUG CODE
		//order_out.print_queue();//DEBUG CODE
		//cout << "order_takers.is_done: " << order_takers.is_done()
			  //<< endl;
		//cout << "fetch_bot.unit_free(): " << fetch_bot.unit_free()
			  //<< endl << endl;
		//DEBUG END*/
		
		//increments the time at the end of each time loop iteration
		increment_time();
	};
	
	//DEBUG CODE
	//cout << "order_takers queue: " << endl;
	//order_takers.print_buffer();
	//cout << "order_out Queue: " << endl;
	//DEBUG END
	
	//cout << "check15\n";//DEBUG CODE
	
	//cout << "check14\n";//DEBUG CODE
	
	//prints output queue
	order_out->print_queue();
	//cout << "check12\n";//DEBUG CODE
	
	//prints calculation results
	calc_shop->print_stats();
	
	cout << "simulation done\n";
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
