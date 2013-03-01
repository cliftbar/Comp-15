//front.h
//Created by: Cameron Barclift
//Front_Desk class acts as the order reciever from an input buffer,
//class never actually directly reads from the stream or a file.

#ifndef FRONT
#define FRONT

#include <iostream>
#include "queue.h"
#include "buffer.h"

using namespace std;

class Front_Desk
{
public:
	//constructor
	Front_Desk();
	
	//true: done, internal queue empty
	//false: not done, internal queue not empty
	bool is_done();
	
	//returns the next order, removes from class
	Order pass_order();
	
	void increment_time();
	
	void print_buffer();

private:
	//runs the functions to create the input buffer
	void run_buffer();
	
	//holds the next order in line, not stored in the internal
	//order queue
	Order next_order;
	
	Queue* buffer_queue;
	
	//should stay the same as the absolute time
	int desk_time;
	
	bool done;
};

#endif
