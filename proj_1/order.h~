//Created by: Cameron Barclift

#ifndef ORDER
#define ORDER
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct Order
{
	//Unique ID number
	int id;

	//Arrival Time
	int t_arrive;

	//How long after arrival time it takes
	//to find and load into a packing unit
	int t_fetch;

	//How long it takes to get packaged
	int t_pack;

	//determines packaging priority
	string priority;
	
	//time spent in front desk queue
	int front_wait;

	//time spent being fetched
	int fetch_wait;
	
	//time spent in packaging queue
	int pack_wait;

	//time spent interrupted
	int spent_interrupted;

	//time out of simulation
	int t_out;
};

#endif
