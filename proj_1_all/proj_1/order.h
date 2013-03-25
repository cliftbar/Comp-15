
//order.h
//Created by: Cameron Barclift
//struct to hold the orders

#ifndef ORDER
#define ORDER
#include <iostream>
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

	//time out of simulation two (don't consider supreme)
	int t_out_sim1;
	
	//Time out of simulation one (consider supreme)
	int t_out_sim2;
	
	//was order priority swtched
	bool switched;
	
	//which queue was it packed in
	int pack_queue;
};

#endif
