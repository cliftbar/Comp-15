
//pack_boss.cpp
//Created by: Cameron Barclift
//Pack_Boss class holds a dynamic array of packers, the number of which is
//is set by the constant NUM_PACKERS, set in the constructor.

#include "pack_boss.h"
using namespace std;

////////////////////////////////Public Methods////////////////////////

Pack_Boss::Pack_Boss()
{
	NUM_PACKERS = 3;
	all_packers = new Packer[NUM_PACKERS];
	packers_done = false;
}


//takes in an order and passes it to the shortest packer queue
void Pack_Boss::pass_in(Order o_in)
{
	int shortest = find_shortest(o_in.priority == "supreme");
	o_in.pack_queue = shortest;
	all_packers[shortest].insert(o_in);
}

//returns the number of orders ready from all packers
int Pack_Boss::num_orders_up()
{
	int counter = 0;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].order_up()){
		++counter;
		}
	}
		
	return counter;
}

//returns the order of the first packer it comes to who is ready.
//must be called multiple times to get multiple orders.
//if called when there are no orders ready, the program exits with an error
Order Pack_Boss::pass_out()
{	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].order_up()){
			return all_packers[i].pass_to();
		}
	}
	
	//makes the compiler stop complaining, 
	cerr << "No orders ready, fail\n";
	exit(1);
}

//returns true only if all packers are empty
bool Pack_Boss::all_done()
{	
	bool check_done = true;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (!all_packers[i].is_done()){
			check_done = all_packers[i].is_done();
		}
	}
	
	packers_done = check_done;
	
	return packers_done;
}

//increments the time of all packers. Pack_Boss does not keep internal time
void Pack_Boss::increment_time()
{
	for (int i = 0; i < NUM_PACKERS; ++i){
		all_packers[i].increment_time();
	}
}

////////////////////////////////Private Methods////////////////////////

//returns the number of the shortest packer queue
int Pack_Boss::find_shortest(bool supreme)
{
	special_reg_wait = all_packers[0].wait_time(!supreme);
	packer_num = 0;
	
	temp_wait_init(supreme);
	
	if (supreme){
		supreme_case(supreme);
	}else if (!supreme){
		regular_case(supreme);
	}
	return packer_num;
}

//returns whether all of the packers have a supreme order
bool Pack_Boss::all_supreme()
{
	bool supreme_status = true;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].wait_time(true) == 0 ){
			supreme_status = false;
		}
	}
	
	return supreme_status;
}

//initializes the hold time to first packers queue time
void Pack_Boss::temp_wait_init(bool supreme)
{
	if (supreme && all_supreme()){
		temp_wait = all_packers[0].wait_time(supreme);
	}else if (supreme && !all_supreme()){
		temp_wait = all_packers[0].wait_time(!supreme);
	}else{
		temp_wait = all_packers[0].wait_time(supreme);
	}
}

//if all packers have a supreme order
void Pack_Boss::all_supreme_case(bool supreme, int i)
{
	if (all_packers[i].wait_time(supreme) < temp_wait){
		temp_wait = all_packers[i].wait_time(supreme);
		packer_num = i;
	}else if (all_packers[i].wait_time(supreme) == temp_wait){
		if (all_packers[i].wait_time(!supreme) < special_reg_wait){
			special_reg_wait = all_packers[i].wait_time(!supreme);
			packer_num = i;
		}
	}
}

//if all packers do not have a supreme order
void Pack_Boss::not_all_supreme_case(bool supreme, int i)
{
	if (all_packers[i].wait_time(supreme) == 0 &&
	    all_packers[i].wait_time(!supreme) < temp_wait){
		//forces the order to a packer queue with a supreme
		//wait of zero find the queue of these with the
		//shortest regular wait
		temp_wait = all_packers[i].wait_time(!supreme);
		packer_num = i;
	}
}

//if the order is supreme
void Pack_Boss::supreme_case(bool supreme)
{
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_supreme()){
			all_supreme_case(supreme, i);
		}else if (!all_supreme()){
			not_all_supreme_case(supreme, i);
		}
	}
}

//the order is not supreme
void Pack_Boss::regular_case(bool supreme)
{
	for(int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].wait_time(supreme) < temp_wait){
			temp_wait = all_packers[i].wait_time(supreme);
			packer_num = i;
		}
	}
}