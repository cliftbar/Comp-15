//Created by: Cameron Barclift

#ifndef PACKER
#define PACKER
#include <iostream>
#include "queue.h"
#include "order.h"

using namespace std;

class Packer
{
public:
	//constructor
	Packer();
	
	//adds an order to the queue
	void insert(Order o_add);
	
	bool order_ready();
	
	//returns the order that's finished being packed
	Order pass_to();
	
	//returns the wait time of the normal orders
	int wait_time(bool supreme);
	
	//asks if the current order is done
	bool order_up();
	
	//asks if the packer is done with orders
	bool is_done();
	
	void increment_time();
	
	void print_queue();
	
	//DEBUG
	void print_current();
	
private:
	//contains the order currently being packed
	Order curr_order;
	
	//holds the packaging queue
	Queue order_queue;
	
	//holds the supreme queue
	Queue supreme_queue;
	
	//holds the current packing time,
	//resets to zero after every order.
	int curr_time;
	
	//store the time of an order on hold
	int t_interrupt;
	
	Order interrupt_order;
	
	//time required for all items in the queue
	int t_wait;
	
	int t_absolute;
	
	bool o_up;
	
	bool is_order;
		
	//wait time for the supreme orders
	int supreme_wait;
};

#endif