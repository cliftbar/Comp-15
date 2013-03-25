//fetcher.h
//Created by: Cameron Barclift
//fetcher simulates moving an order from the recieving/storage
//area to the next step in processing. The fetcher only handles
//one order at a time, and doesn't consider supreme customers

#include "fetcher.h"

////////////////PUBLIC METHODS///////////////////////

//Constructor
Fetcher::Fetcher()
{
	curr_time = 0;
	unit_status = true;
}

//stores an order passes into it, sets the unit status 
//to not free
void Fetcher::get_order(Order o_in)
{
	curr_order = o_in;
	unit_status = false;
	curr_time = 0;
}

//returns the order stored inside.  Will return the order
//even if the fetching is not complete, must check if the fetch
//is done first.  then resets the internal time and sets the unit
//to free
Order Fetcher::deliver_order()
{
	unit_status = true;
	//curr_time = 0;
	return curr_order;
}


bool Fetcher::unit_free()
{
	return unit_status;
}

//if the fetch time matches the time required for 
//an order to be fetched, return true
//otherwise, return false
bool Fetcher::order_ready()
{
	cout << "unit_free: " << unit_free() << endl;
	cout << "curr_time: " << curr_time << endl;
	cout << "curr_order.t_fetch: " << curr_order.t_fetch << endl;
	if (!unit_free()){
		return (curr_time >= curr_order.t_fetch);
	}else {
		return false;
	}
}

void Fetcher::increment_time()
{
	++curr_order.fetch_wait;
	++curr_time;
}

//Debug print function
void Fetcher::print_debug()
{
	cout << "Fetcher, Current Order ID: " << curr_order.id << endl;
	cout << "Current Time: " << curr_time << endl;
	cout << "Current order fetch time: " << curr_order.t_fetch << endl;
	cout << "Current Order fetch_wait: " << curr_order.fetch_wait << endl;
	
	cout << endl;
}
