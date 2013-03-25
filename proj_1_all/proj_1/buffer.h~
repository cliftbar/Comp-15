//buffer.cpp
//Created by: Cameron Barclift
//need a destructor
//Buffer reads input from the standard stream and stores the relevant
//data into a queue.  It can pass out a copy of the buffer queue

#ifndef FRONT_DESK
#define FRONT_DESK
#include <iostream>
#include "order.h"
#include "queue.h"
#include "buffer.h"

//Takes in orders and maintains the order queue
class Buffer
{
public:
	//cosntructor, does nothing on purpose
	Buffer();
	
	//reads in and stores the file/stream input into a queue
	void read_in();
	
	//returns a pointer to a copy of the buffer queue
	Queue* pass_queue();
	
	//prints orders in the buffer, in order
	void print_orders();
	
private:
	
	//Queue for orders read in by Buffer
	Queue order_queue;
};

#endif
