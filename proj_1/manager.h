
#ifndef MANAGER
#define MANAGER
#include <iostream>
#include <cstdlib>
#include <string>
#include "queue.h"
#include "buffer.h"
#include "queue.h"

using namespace std;

//coordinates warehouse floor activities
class Manager
{
public:
	Manager();
	//runs all of the functions required for
	//a time interval on the floor
	void run_floor();
	//Prints the final report on floor activities
	//void report();
private:
	//increments the time forward one unit
	void increment_time();
	//determines the shortest queue among
	//the available packers
	//void shortest_queue();
	
	//array of pointers to fetchers,
	//array is static
	//Fetching_Unit* fetchers[NUM_FETCHERS];
	
	//array of pointers to packers,
	//array is static
	//Packing_Unit* packers[NUM_PACKERS];
	
	//holds a pointer to the packer with the shortest queue
	//Packing_Unit* next_packer;
	
	//master time for the simulation
	int absolute_time;
	
	Queue order_queue;
	
};

#endif
