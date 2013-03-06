//manager.cpp
//Created by: Cameron Barclift
//Creates the input buffer, then runs the two simulations.
//Mainly just a wrapper for the simulations and buffer.
#include <iostream>
#include "manager.h"

using namespace std;

Manager::Manager()
{
	//default constructor
}

void Manager::run_simulations()
{
	Buffer sales;
	Stats sim_1_stats(false);
	Stats sim_2_stats(true);
	
	sales.read_in();
	Queue* temp_queue;
	
	//sales.print_orders();//DEBUG CODE
	
	Simulation sim_1(false, sales.pass_queue());
	temp_queue = sim_1.run_sim();
	
	Simulation sim_2(true, temp_queue);
	temp_queue = sim_2.run_sim();
	
	for (int i = 0; i < temp_queue->get_length(); ++i){
		sim_1_stats.get_order(temp_queue->remove());
		sim_1_stats.run_calcs();
		sim_2_stats.get_order(sim_1_stats.return_order());
		sim_2_stats.run_calcs();
		temp_queue->insert(sim_2_stats.return_order());
	}
	
	temp_queue->print_queue();
	
	sim_1_stats.print_stats();
	sim_2_stats.print_stats();		
}
	
