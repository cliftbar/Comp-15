//Created by: Cameron Barclift

#ifndef FRONT_DESK
#define FRONT_DESK
#include <iostream>
#include <cstdlib>
#include <string>
#include "order.h"
#include "queue.h"
#include "buffer.h"

//Takes in orders and maintains the order queue
class Buffer
{
public:
	//cosntructor
	Buffer();
	
	void read_in();
	
	//Asks if there is an order in the queue
	bool is_order();
	
	//Passes an order from the queue
	//Does not check if there is an order or not
	Queue pass_queue();
	
	void print_orders();
	
private:
	//Queue for orders read in by Buffer
	Queue order_queue;
};

#endif