//packer.cpp
//Created by: Cameron Barclift
//Packer class, handles packing an order.
//Class has two queues, one for supreme customers
//and one for regular customers.  If a supreme order is passed in,
//and a regular order is being packed, the regular order is interrupted
//until there are no more supreme orders in the packer.  Orders cannot
//be held in the packer, they must be taken immediately when ready or
//the packer will fail.

#include "packer.h"
using namespace std;

Packer::Packer()
{
	curr_time = 0;
	t_wait = 0;
	t_absolute = 0;
	t_interrupt = 0;
	supreme_wait = 0;
	o_up = false;
	is_order = false;
	interrupt_order.priority = "NULL";
}

//inserts an order into the correct queue.
//Cases:
//	supreme order passed in, current order supreme,
//		new order goes to supreme queue
//	supreme order passed in, current order regular,
//		new order interrupts current order
//	new order is regular, goes to regular queue
//	no current order, new order starts getting packed
void Packer::insert(Order o_in)
{	
	//cout << "Order in ID: " << o_in.id << endl;//DEBUG CODE
	//cout << "Order in pack time: " << o_in.t_pack << endl
		  //<< endl;//DEBUG CODE
	
	cout << "is_order: " << is_order << endl;
	if (is_order){
		//there is an order currently being packed
		//cout << "There is an order\n";//DEBUG CODE
		if (o_in.priority == "supreme" && curr_order.priority == "supreme"){
			//current order is supreme and new order is supreme
			//cout << "new order supreme, curr_order supreme\n";//DEBUG
			supreme_queue.insert(o_in);
		}else if (o_in.priority == "supreme" &&
				curr_order.priority == "regular"){
			//current order is regular, new order is supreme
			//cout << "new order supreme, curr_order regular\n";//DEBUG
			interrupt_order = curr_order;
			t_interrupt = curr_time;
			curr_time = 0;
			curr_order = o_in;
		}else{
			//new order is regular
			//cout << "new order regular\n";//DEBUG CODE
			order_queue.insert(o_in);
		}
	}else if (!is_order){
		//No current order
		//cout << "no order present\n";//DEBUG CODE
		curr_time = 0;
		curr_order = o_in;
	}
	
	t_wait += o_in.t_pack;
	//cout << "t_wait after insert: " << t_wait << endl;//DEBUG CODE
	
	//increase supreme wait time if order is supreme
	if (o_in.priority == "supreme"){
		supreme_wait += o_in.t_pack;
	}
	
	//Says that there is an order currently being packed
	is_order = true;
}

//passes an order out of the packer,
//and sets next order in line as current order
//Cases:
//	supreme queue is empty and there is no order interrupted,
//	  current order must be regular
//	   if regular queue is not empty, set next regular order to current order
//	   if regular queue is empty, say that there are no current orders
//	   current pack time set to zero
//	supreme queue is empty and there is an order interrupted,
//	current order must be supreme
//	   set interrupted order to current order,
//	   current pack time set to interrupt time
//	   (the current time of the interrupted order)
//	supreme queue is not empty, take from supreme queue,
//	   current pack time is set to zero
Order Packer::pass_to()
{
	Order temp;
	
	temp = curr_order;
	
	if (supreme_queue.is_empty() && t_interrupt == 0){
		//supreme queue is empty, no interrupted order,
		//current order is necessarily regular
		//cout << "supreme_queue empty, no interrupt_order\n";//DEBUG CODE
		if (!order_queue.is_empty()){
			curr_order = order_queue.remove();
			curr_order.pack_wait = t_absolute - curr_order.front_wait
										- curr_order.fetch_wait;
		}else{
			is_order = false;
		}
		curr_time = 0;
	}else if (supreme_queue.is_empty() && t_interrupt != 0){
		//supreme queue empty, there is an interrupted order,
		//current order is necessarily supreme
		//cout << "supreme_queue empty, curr_order supreme,
			  //interrupt_order present\n";//DEBUG CODE
		curr_order = interrupt_order;
		curr_time = t_interrupt;
		t_interrupt = 0;
		interrupt_order.priority = "NULL";
	}else if (!supreme_queue.is_empty()){
		//supreme queue is not empty
		//cout << "supreme_queue not empty\n";//DEBUG CODE
		curr_order = supreme_queue.remove();
		curr_order.pack_wait = t_absolute - curr_order.front_wait
									- curr_order.fetch_wait;
		curr_time = 0;
	}
	
	//Says that an order is not ready anymore
	o_up = false;
	
	return temp;
}

//Returns the requested wait time
int Packer::wait_time(bool supreme)
{
	if (!supreme){
		return t_wait;
	}else {
		return supreme_wait;
	}
}

//returns whether an order is ready, an order is ready when the current
//time is the same as the pack time.
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

//true if the packer is done, which means
//there is no order being packed and both queues are empty
bool Packer::is_done()
{
	
	if (order_queue.is_empty() && supreme_queue.is_empty() && !is_order){
		return true;
	}else {
		return false;
	}
}

//increments the time.  current time and absolute time are increased,
//wait times are decreased unless they are zero, and the time spent
//interrupted by the interrupted order is increased
void Packer::increment_time()
{
	++curr_time;
	++t_absolute;
	if (t_wait > 0){
		--t_wait;
	}
	if (supreme_wait > 0){
		--supreme_wait;
	}
	if (interrupt_order.priority != "NULL"){
		++interrupt_order.spent_interrupted;
	}
}

//prints the regular and supreme queues
void Packer::print_queue()
{
	cout << "Packer queue, normal: " << endl;
	order_queue.print_queue();
	cout << "Queue length: " << order_queue.get_length() << endl << endl;
	
	cout << "Packer queue, supreme: " << endl;
	supreme_queue.print_queue();
	cout << "Queue length: " << supreme_queue.get_length() << endl << endl;
}

//debug function
void Packer::print_current()
{
	cout << "Current Order " << curr_order.id << endl;
	cout << "fetch time " << curr_order.t_fetch << endl;
	cout << "Fetch wait: " << curr_order.fetch_wait << endl;
	cout << "Pack wait: " << curr_order.pack_wait << endl;
	cout << "front wait: " << curr_order.front_wait << endl;
	cout << "time out sim1: " << curr_order.t_out_sim1 << endl;
	cout << "time out sim2: " << curr_order.t_out_sim2 << endl;
	cout << "pack time " << curr_order.t_pack << endl;
	cout << "current time: " << curr_time << endl;
	cout << "absolute time: " << t_absolute << endl;
}
