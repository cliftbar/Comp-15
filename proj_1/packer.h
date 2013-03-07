//packer.h
//Created by: Cameron Barclift
//Packer class, handles packing an order.
//Class has two queues, one for supreme customers
//and one for regular customers.  If a supreme order is passed in,
//and a regular order is being packed, the regular order is interrupted
//until there are no more supreme orders in the packer.  Orders cannot
//be held in the packer, they must be taken immediately when ready or
//the packer will fail.

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
	
	//True if an order is ready
	bool order_ready();
	
	//returns the order that's finished being packed
	Order pass_to();
	
	//returns the wait time of the normal orders
	int wait_time(bool supreme);
	
	//asks if the current order is done
	bool order_up();
	
	//asks if the packer is done with orders
	bool is_done();
	
	//increments internal times: current pack time, absolute simulation time
	//total wait time, and supreme wait time (if necessary)
	void increment_time();
	
	void print_queue();
	
	//DEBUG
	void print_current();
	
private:
	
	//logic for inserting when an order currently being packed
	void insert_is_order(Order o_in);
	
	//logic for inserting when no order is currently being packed
	void insert_not_is_order(Order o_in);
	
	//logic for first case in pass_to function
	void pass_to_case_1();
	
	//logic for second case in pass_to function
	void pass_to_case_2();
	
	//logic for third case in pass_to function
	void pass_to_case_3();
	
	//contains the order currently being packed
	Order curr_order;
	
	//holds the packaging queue
	Queue order_queue;
	
	//holds the supreme queue
	Queue supreme_queue;
	
	//holds the current packing time,
	//resets to zero after every order.
	int curr_time;
	
	//store the time of the order on hold
	int t_interrupt;
	
	//holds the order that has been interrupted
	Order interrupt_order;
	
	//time required for all items in the queue
	int t_wait;
	
	//absolute simulation time, needed to set
	//time spent in packing queue
	int t_absolute;
	
	//True if an order has finished packing
	bool o_up;
	
	//True if there is an order in the queue
	bool is_order;
		
	//wait time for the supreme orders
	int supreme_wait;
};

#endif
