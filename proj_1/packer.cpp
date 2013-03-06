
#include "packer.h"
using namespace std;

Packer::Packer(/*bool is_supreme*/)
{
	//supreme = is_supreme;
	curr_time = 0;
	t_wait = 0;
	t_absolute = 0;
	t_interrupt = 0;
	supreme_wait = 0;
	o_up = false;
	is_order = false;
	interrupt_order.priority = "NULL";
}

void Packer::consider_supreme(bool do_supreme)
{
	supreme = do_supreme;
}

void Packer::insert(Order o_in)
{	
	//cout << "Order in ID: " << o_in.id << endl;//DEBUG CODE
	//cout << "Order in pack time: " << o_in.t_pack << endl << endl;//DEBUG CODE
	
	if (is_order){
		//cout << "There is an order\n";//DEBUG CODE
		if (o_in.priority == "supreme" && curr_order.priority == "supreme"){
			//cout << "new order supreme, curr_order supreme\n";//DEBUG CODE
			supreme_queue.insert(o_in);
		}else if (o_in.priority == "supreme" && curr_order.priority == "regular"){
			//cout << "new order supreme, curr_order regular\n";//DEBUG CODE
			interrupt_order = curr_order;
			t_interrupt = curr_time;
			curr_time = 0;
			curr_order = o_in;
		}else{
			//cout << "new order regular\n";//DEBUG CODE
			order_queue.insert(o_in);
		}
	}else if (!is_order){
		//cout << "no order present\n";//DEBUG CODE
		curr_time = 0;
		curr_order = o_in;
	}
	
	t_wait += o_in.t_pack;
	//cout << "t_wait after insert: " << t_wait << endl;//DEBUG CODE
	
	if (o_in.priority == "supreme"){
		supreme_wait += o_in.t_pack;
	}
	is_order = true;
}

Order Packer::pass_to()
{
	Order temp;
	
	temp = curr_order;
	
	if (supreme_queue.is_empty() && t_interrupt == 0){
		//cout << "supreme_queue empty, no interrupt_order\n";//DEBUG CODE
		if (!order_queue.is_empty()){
			curr_order = order_queue.remove();
			curr_order.pack_wait = t_absolute - curr_order.front_wait - curr_order.fetch_wait;
		}else{
			is_order = false;
		}
		curr_time = 0;
	}else if (supreme_queue.is_empty() && curr_order.priority == "supreme" && t_interrupt != 0){
		//cout << "supreme_queue empty, curr_order supreme, interrupt_order present\n";//DEBUG CODE
		curr_order = interrupt_order;
		curr_time = t_interrupt;
		t_interrupt = 0;
		interrupt_order.priority = "NULL";
	}else if (!supreme_queue.is_empty()){
		//cout << "supreme_queue not empty\n";//DEBUG CODE
		curr_order = supreme_queue.remove();
		curr_order.pack_wait = t_absolute - curr_order.front_wait - curr_order.fetch_wait;
		curr_time = 0;
	}
	
	o_up = false;
	
	return temp;
}

int Packer::wait_time(bool supreme)
{
	if (!supreme){
		return t_wait;
	}else {
		return supreme_wait;
	}
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
	
	if (order_queue.is_empty() && supreme_queue.is_empty() && !is_order){
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
	if (supreme_wait > 0){
		--supreme_wait;
	}
	if (interrupt_order.priority != "NULL"){
		++interrupt_order.spent_interrupted;
	}
}

void Packer::print_queue()
{
	cout << "Packer queue, normal: " << endl;
	order_queue.print_queue();
	cout << "Queue length: " << order_queue.get_length() << endl << endl;
	
	cout << "Packer queue, supreme: " << endl;
	supreme_queue.print_queue();
	cout << "Queue length: " << supreme_queue.get_length() << endl << endl;
}

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
