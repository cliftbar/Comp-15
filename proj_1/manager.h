
#ifndef manager.h
#define
#include <iostream>
#include <cstdlib>
#include <string>
#include "fetchers"
#include "packer"
#include "front"
#include "calculator"
#include "queue"

using namespace std

//coordinates warehouse floor activities
class Manager
{
public:
	//runs all of the functions required for
	//a time interval on the floor
	void run_floor();
	//Prints the final report on floor activities
	void report();
private:
	//increments the time forward one unit
	void increment_time();
	//determines the shortest queue among
	//the available packers
	void shortest_queue();
	
	//array of pointers to fetchers,
	//array is static
	Fetching_Unit* fetchers[NUM_FETCHERS];
	//array of pointers to packers,
	//array is static
	Packing_Unit* packers[NUM_PACKERS];
	//holds a pointer to the packer with the shortest queue
	Packing_Unit* next_packer;
	//master time for the simulation
	int absolute_time;
	
};

#endif
