
//pack_boss.cpp
//Created by: Cameron Barclift
//Pack_Boss class holds a dynamic array of packers, the number of which is
//is set by the constant NUM_PACKERS, set in the constructor.

#include "pack_boss.h"
using namespace std;

Pack_Boss::Pack_Boss()
{
	NUM_PACKERS = 3;
	all_packers = new Packer[NUM_PACKERS];
	packers_done = false;
}


//takes in an order and passes it to the shortest packer queue
void Pack_Boss::pass_in(Order o_in)
{
	//cout << "check 1 \n" << endl;//DEBUG
	int shortest = find_shortest(o_in.priority == "supreme");
	//cout << "shortest: " << shortest << endl;//DEBUG
	o_in.pack_queue = shortest;
	all_packers[shortest].insert(o_in);
}

//returns the number of orders ready from all packers
int Pack_Boss::num_orders_up()
{
	//cout << "check 2 \n" << endl;//DEBUG
	int counter = 0;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].order_up()){
		++counter;
		}
	}
	
	//cout << "check 10 \n" << endl;//DEBUG
	
	return counter;
}

//returns the order of the first packer it comes to who is ready.
//must be called multiple times to get multiple orders.
//if called when there are no orders ready, the program exits with an error
Order Pack_Boss::pass_out()
{
	//cout << "check 3 \n" << endl;//DEBUG
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].order_up()){
			return all_packers[i].pass_to();
		}
	}
	
	//makes the compiler stop complaining, 
	cerr << "No orders ready, fail\n";
	exit(1);
}

//returns the number of the shortest packer queue
int Pack_Boss::find_shortest(bool supreme)
{
	//cout << "check 4 \n" << endl;//DEBUG
	int temp_wait;
	int packer_num = 0;
	
	//initializes the hold time to first packers queue time
	if (supreme && all_supreme()){
		cout << "check1\n";
		temp_wait = all_packers[0].wait_time(supreme);
	}else{
		cout << "check2\n";
		cout << "supreme: " << supreme << ", !supreme: " << (supreme == false) << endl;
		temp_wait = all_packers[0].wait_time(supreme);
	}
	
	cout << "temp_wait: " << temp_wait << endl;
	
	if (supreme){
		//if the order is supreme
		cout << "check 9" << endl;//DEBUG
		for (int i = 0; i < NUM_PACKERS; ++i){
			if (all_supreme()){
				//if all packers have a supreme order
				//cout << "check 10" << endl;//DEBUG
				if (all_packers[i].wait_time(supreme) < temp_wait){
					temp_wait = all_packers[i].wait_time(supreme);
					packer_num = i;
				}
			}else if (!all_supreme()){
				//if all packers do not have a supreme order
				//cout << "check 11" << endl;//DEBUG
				if (all_packers[i].wait_time(supreme) == 0 &&
				    all_packers[i].wait_time(!supreme) < temp_wait){
					//forces the order to a packer queue with a supreme
					//wait of zero find the queue of these with the
					//shortest regular wait
					temp_wait = all_packers[i].wait_time(supreme);
					packer_num = i;
				}
			}
		}
	}else if (!supreme){
		//the order is not supreme
		//cout << "check 8" << endl;//DEBUG
		//cout << "NUM_PACKERS: " << NUM_PACKERS << endl;
		for(int i = 0; i < NUM_PACKERS; ++i){
			//cout << "check 9" << endl;//DEBUG
			//cout << "all_packers[" << i << "].wait_time.(supreme): "
			//	<< all_packers[i].wait_time(supreme) << endl;
			//cout << "temp_wait: " << temp_wait << endl;
			if (all_packers[i].wait_time(supreme) < temp_wait){
			//	cout << "check9\n";
				temp_wait = all_packers[i].wait_time(supreme);
				packer_num = i;
			}
		}
		//cout << "packer num: " << packer_num << endl;
		//cout << "check 10" << endl;//DEBUG
	}
	//cout << "check 8 \n" << endl;//DEBUG
	//cout << "packer_num: " << packer_num << endl;//DEBUG
	return packer_num;
}

//returns true only if all packers are empty
bool Pack_Boss::all_done()
{
	//cout << "check 5 \n" << endl;//DEBUG
	
	bool check_done = true;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		//cout << "all_packers[" << i << "].is_done(): "
			  //<< all_packers[i].is_done() << endl;//DEBUG CODE
		if (!all_packers[i].is_done()){
			check_done = all_packers[i].is_done();
		}
	}
	
	packers_done = check_done;
	
	return packers_done;
}

//Debug function
void Pack_Boss::print_packers()
{
	for (int i = 0; i < NUM_PACKERS; ++i){
		cout << "Packer[" << i << "]: " << endl;
		all_packers[i].print_current();
		cout << "regular all_packers[" << i<< "].wait_time(false): "
			<< all_packers[i].wait_time(false) << endl;
		cout << "supreme all_packers[" << i<< "].wait_time(true): "
			<< all_packers[i].wait_time(true) << endl << endl;
	}
}

//increments the time of all packers. Pack_Boss does not keep internal time
void Pack_Boss::increment_time()
{
	//cout << "check 6 \n" << endl;//DEBUG
	for (int i = 0; i < NUM_PACKERS; ++i){
		all_packers[i].increment_time();
	}
}

bool Pack_Boss::all_supreme()
{
	bool supreme_status = true;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].wait_time(true) == 0 ){
			supreme_status = false;
		}
	}
	
	//cout << "all supreme: " << supreme_status << endl;//DEBUG
	return supreme_status;
}
