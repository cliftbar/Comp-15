
#ifndef FRONT
#define FRONT

#include <iostream>
#include <cstdlib>
#include <string>
#include "queue.h"
#include "buffer.h"

using namespace std;

class Front_Desk
{
public:
	Front_Desk();
	bool is_done();
	bool order_arrived();
	Order pass_order();
	void increment_time();
	void print_buffer();

private:
	void run_buffer();
	Order next_order;
	Queue* buffer_queue;
	int desk_time;
	bool done;
};

#endif
