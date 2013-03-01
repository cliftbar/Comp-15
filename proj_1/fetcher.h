//fetcher.h
//Created by: Cameron Barclift
//fetcher simulates moving an order from the recieving/storage
//area to the next step in processing. The fetcher only handles
//one order at a time, and doesn't consider supreme customers

#ifndef FETCHER
#define FETCHER
#include <iostream>
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
	
	//passes order out of the fetcher
	Order deliver_order();
	
	//determines if the fetching unit is free,
	bool unit_free();
	
	//determines if the current order is completely fetched
	//True if order fetch complete
	//False if order fetch not complete
	//False if no order currently
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
