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
	sales.read_in();
	//sales.print_orders();//DEBUG CODE
	
	Simulation sim_1(false, sales.pass_queue());
	Simulation sim_2(true, sales.pass_queue());
	
	sim_1.run_sim();
	sim_2.run_sim();
}
	
