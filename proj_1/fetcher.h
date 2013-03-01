//Created by: Cameron Barclift

#ifndef FETCHER
#define FETCHER
#include <iostream>
#include <cstdlib>
#include <string>
#include "order.h"
#include "queue.h"

using namespace std;

class Fetcher
{
public:
	//default constructor
	Fetcher();
	
	//picks up order
	void get_order(Order order_in);
	
	//passes order to packer
	Order deliver_order();
	
	//determines if the fetching unit is free,
	bool unit_free();
	
	bool order_ready();
	
	//increments the internal time and
	//the time of held order, also updates the
	//queue time
	void increment_time();
	
	void print_debug();
	
private:
	//holds the current order
	Order curr_order;
	
	//holds the current fetch time,
	//resets to zero after every order
	int curr_time;
	
	//holds status of unit
	//true for free, false for not free
	bool unit_status;
};
#endif