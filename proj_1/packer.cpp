
#include "packer.h"
using namespace std;

Packer::Packer()
{
	curr_time = 0;
	t_wait = 0;
	t_absolute = 0;
	o_up = false;
	is_order = false;
}

void Packer::insert(Order o_in)
{	
	//cout << "Order in ID: " << o_in.id << endl;//DEBUG CODE
	//cout << "Order in pack time: " << o_in.t_pack << endl << endl;//DEBUG CODE
	
	if (is_order){
		order_queue.insert(o_in);
	}else if (!is_order){
		curr_time = 0;
		curr_order = o_in;
	}
	
	t_wait = t_wait + o_in.t_pack;
	is_order = true;
}

Order Packer::pass_to()
{
	Order temp;
	
	temp = curr_order;
	if (!order_queue.is_empty()){
		curr_order = order_queue.remove();
		curr_order.pack_wait = t_absolute - curr_order.front_wait - curr_order.fetch_wait;
	}else{
		is_order = false;
	}
	
	
	//t_wait = t_wait - temp.t_pack;
	o_up = false;
	curr_time = 0;
	
	return temp;
}

int Packer::wait_time()
{
	return t_wait;
}

bool Packer::order_up()
{
	//cout << "curr_order.id: " << curr_order.id << endl;
	//cout << "curr_order.t_pack: " << curr_order.t_pack << endl;
	//cout << "curr_time: " << curr_time << endl;
	if (is_order){
		o_up = curr_order.t_pack == curr_time;
	}else {
		o_up = false;
	}
		
	//cout << "Order_Up: " << o_up << endl;
	return o_up;
}

bool Packer::is_done()
{
	
	if (order_queue.is_empty() && !is_order){
		return true;
	}else {
		return false;
	}
}

void Packer::increment_time()
{
	++curr_time;
	++t_absolute;
	if (t_wait > 0){
		--t_wait;
	}
}

void Packer::print_queue()
{
	cout << "Packer queue, normal: " << endl;
	order_queue.print_queue();
	cout << "Queue length: " << order_queue.get_length() << endl << endl;
}

void Packer::print_current()
{
	cout << "Current Order " << curr_order.id << endl;
	cout << "fetch time " << curr_order.t_fetch << endl;
	cout << "Fetch wait: " << curr_order.fetch_wait << endl;
	cout << "Pack wait: " << curr_order.pack_wait << endl;
	cout << "front wait: " << curr_order.front_wait << endl;
	cout << "time out: " << curr_order.t_out << endl;
	cout << "pack time " << curr_order.t_pack << endl;
	cout << "current time: " << curr_time << endl;
	cout << "absolute time: " << t_absolute << endl;
}