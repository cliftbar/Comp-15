//manager.h
//Created by: Cameron Barclift
//Manager class contains everything to run the simulation.

#ifndef MANAGER
#define MANAGER
#include <iostream>
#include "order.h"
#include "fetcher.h"
#include "queue.h"
#include "buffer.h"
#include "front.h"

using namespace std;

//coordinates warehouse floor activities
class Manager
{
public:
	//constructor
	Manager();
	
	//runs all of the functions required for
	//a time interval on the floor
	void run_floor();
	
	//Prints the final report on floor activities
	//void report();
	
private:
	//increments the time forward one unit
	//and calls the time functions of member variables
	void increment_time();
		
	//master time for the simulation
	int absolute_time;
	
	Front_Desk order_takers;
	
	Fetcher fetch_bot;
	
	//temporary queue for debugging purposes
	Queue* order_queue;
	
};

#endif