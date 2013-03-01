
#include "front.h"

Front_Desk::Front_Desk()
{
	desk_time = 0;
	done = false;
	buffer_queue = NULL;
	run_buffer();
}

void Front_Desk::run_buffer()
{
	Buffer sales;
	
	sales.read_in();
	
	//sales.print_orders();//DUBUG CODE
	buffer_queue = sales.pass_queue();
	
	if (!buffer_queue->is_empty()){
		next_order = buffer_queue->remove();
	}
}

bool Front_Desk::is_done()
{
	//cout << "buffer queue empty: " << buffer_queue->is_empty() << endl;
	return done;
}


//For manager use ONLY!!!!!!!
void Front_Desk::increment_time()
{
	++desk_time;
}

Order Front_Desk::pass_order()
{
	Order r_order = next_order;
	
	if (!buffer_queue->is_empty()){
		next_order = buffer_queue->remove();
	}else if (buffer_queue->is_empty()){
		done = true;
	}
	
	r_order.fetch_wait = desk_time;
	//cout << "pass_order id: " << r_order.id << endl;
	
	return r_order;
}

void Front_Desk::print_buffer()
{
	buffer_queue->print_queue();
}