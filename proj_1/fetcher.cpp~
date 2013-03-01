
#include "fetcher.h"

Fetcher::Fetcher()
{
	curr_time = 0;
	unit_status = true;
}

void Fetcher::get_order(Order o_in)
{
	curr_order = o_in;
	unit_status = false;
}

Order Fetcher::deliver_order()
{
	unit_status = true;
	curr_time = 0;
	return curr_order;
}

bool Fetcher::unit_free()
{
	return unit_status;
}

bool Fetcher::order_ready()
{
	return (curr_time == curr_order.t_fetch);
}

void Fetcher::increment_time()
{
	++curr_order.fetch_wait;
	++curr_time;
}

void Fetcher::print_debug()
{
	cout << "Fetcher, Current Order ID: " << curr_order.id << endl;
	cout << "Current Time: " << curr_time << endl;
	cout << "Current order fetch time: " << curr_order.t_fetch << endl;
	
	cout << endl;
}