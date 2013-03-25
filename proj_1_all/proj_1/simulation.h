
//simulation.h
//Created by: Cameron Barclift
//Simulation class contains everything to run the simulation.

#ifndef SIMULATION
#define SIMULATION
#include <iostream>
#include "order.h"
#include "fetcher.h"
#include "queue.h"
#include "buffer.h"
#include "front.h"
#include "pack_boss.h"

using namespace std;

//coordinates warehouse floor activities
class Simulation
{
public:
	//Preferred constructor, takes in whether to consider supreme orders
	//and a pointer to a copy of the buffer queue
	Simulation(bool is_supreme, Queue* sales_queue);
	
	//runs all of the functions required for
	//a time interval on the floor
	Queue* run_sim();
	
	//Prints the final report on floor activities
	//void report();
	
private:
	//increments the time forward one unit
	//and calls the time functions of member variables
	void increment_time();
		
	//master time for the simulation
	int absolute_time;
	
	bool supreme;
	
	void un_switch();
	
	//loop to move order from pack_chief to output queue
	void pack_chief_loop();
	
	//loop to move order from fetcher to pack_chief
	void fetch_bot_loop();
	
	//Loop for moving an order from order_takers to fetcher
	void order_takers_loop();
	
	Front_Desk* order_takers;
	
	Fetcher fetch_bot;
	
	Pack_Boss pack_chief;
		
	//output queue
	Queue* order_out;
	
	//temporary hold order
	Order next_order;
};

#endif
