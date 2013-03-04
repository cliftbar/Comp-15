
#include "pack_boss.h"
using namespace std;

Pack_Boss::Pack_Boss()
{
	NUM_PACKERS = 2;
	all_packers = new Packer[NUM_PACKERS];
	packers_done = false;
}

void Pack_Boss::pass_in(Order o_in)
{
	//cout << "check 1 \n" << endl;//DEBUG
	int shortest = find_shortest(o_in.priority == "supreme");
	cout << "shortest: " << shortest << endl;//DEBUG
	all_packers[shortest].insert(o_in);
}

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

Order Pack_Boss::pass_out()
{
	//cout << "check 3 \n" << endl;//DEBUG
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].order_up()){
			return all_packers[i].pass_to();
		}
	}
	
	exit(1);
}

int Pack_Boss::find_shortest(bool supreme)
{
	//cout << "check 4 \n" << endl;//DEBUG
	int temp_wait;
	int packer_num;
	
	if (supreme && all_supreme()){
		temp_wait = all_packers[0].wait_time(supreme);
	}else{
		temp_wait = all_packers[0].wait_time(!supreme);
	}
	
	if (supreme){
		cout << "check 9" << endl;//DEBUG
		for (int i = 0; i < NUM_PACKERS; ++i){
			if (all_supreme()){
				cout << "check 10" << endl;//DEBUG
				if (all_packers[i].wait_time(supreme) < temp_wait){
					packer_num = i;
				}
			}else if (!all_supreme()){
				cout << "check 11" << endl;//DEBUG
				if (all_packers[i].wait_time(supreme) == 0 && (all_packers[i].wait_time(!supreme) < temp_wait)){
					packer_num = i;
				}
			}
		}
	}else if (!supreme){
		cout << "check 8" << endl;//DEBUG
		for(int i = 0; i < NUM_PACKERS; ++i){
			if (all_packers[i].wait_time(supreme) < temp_wait){
				packer_num = i;
			}
		}
	}
	//cout << "check 8 \n" << endl;//DEBUG
	cout << "packer_num: " << packer_num << endl;//DEBUG
	return packer_num;
}

bool Pack_Boss::all_done()
{
	//cout << "check 5 \n" << endl;//DEBUG
	
	bool check_done = true;
	
	for (int i = 0; i < NUM_PACKERS; ++i){
		if (!all_packers[i].is_done()){
			check_done = all_packers[i].is_done();
		}
	}
	
	packers_done = check_done;
	
	return packers_done;
}

void Pack_Boss::print_packers()
{
	for (int i = 0; i < NUM_PACKERS; ++i){
		cout << "Packer[" << i << "]: " << endl;
		all_packers[i].print_current();
		cout << "regular all_packers[" << i<< "].wait_time(false): " << all_packers[i].wait_time(false) << endl;
		cout << "supreme all_packers[" << i<< "].wait_time(true): " << all_packers[i].wait_time(true) << endl << endl;
	}
}

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
	
	cout << "all supreme: " << supreme_status << endl;//DEBUG
	return supreme_status;
}
