//Created by: Cameron Barclift

#ifndef fetcher.h
#define
#include <iostream>
#include <cstdlib>
#include <string>
#include "order"
#include "queue"

using namespace std

class Fetching_Unit
{
public:
	//default constructor
	Fetching_Unit();
	//picks up order
	void get_order(Order order_in);
	//passes order to packer
	Order deliver_order();
	//determines if the fetching unit is free,
	bool unit_free();
	bool order_ready();
private:
	//Passes the order to the indicated unit
	void choose_queue(Packing_Unit* pass_to);
	//holds the current order
	Order curr_order;
	//increments the internal time and
	//the time of held order, also updates the
	//queue time
	void increment_time();
	//holds the current fetch time,
	//resets to zero after every order
	int curr_time;
	//holds status of unit, free or not free
	bool unit_status;
};
#endif