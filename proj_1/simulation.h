//simulation.h
//Created by: Cameron Barclift
//Manager class contains everything to run the simulation.

#ifndef SIMULATION
#define SIMULATION
#include <iostream>
#include "order.h"
#include "fetcher.h"
#include "queue.h"
#include "buffer.h"
#include "front.h"
#include "pack_boss.h"
#include "stats.h"

using namespace std;

//coordinates warehouse floor activities
class Simulation
{
public:
	//constructor
	Simulation(bool is_supreme, Queue* sales_queue);
	
	//runs all of the functions required for
	//a time interval on the floor
	void run_sim();
	
	//Prints the final report on floor activities
	//void report();
	
private:
	//increments the time forward one unit
	//and calls the time functions of member variables
	void increment_time();
		
	//master time for the simulation
	int absolute_time;
	
	bool supreme;
	
	void final_steps();
	
	Front_Desk* order_takers;
	
	Fetcher fetch_bot;
	
	Pack_Boss pack_chief;
	
	Stats* calc_shop;
	
	//temporary queue for debugging purposes
	Queue* order_queue;
};

#endif
