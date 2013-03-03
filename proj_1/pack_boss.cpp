
#include "pack_boss.h"
using namespace std;

Pack_Boss::Pack_Boss()
{
	NUM_PACKERS = 3;
	all_packers = new Packer[NUM_PACKERS];
	packers_done = false;
}

void Pack_Boss::pass_in(Order o_in)
{
	//cout << "check 1 \n" << endl;//DEBUG
	int shortest = find_shortest();
	//cout << "shortest: " << shortest << endl;//DEBUG
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

int Pack_Boss::find_shortest()
{
	//cout << "check 4 \n" << endl;//DEBUG
	
	int temp_wait = all_packers[0].wait_time();
	//cout << "check 7 \n" << endl;//DEBUG
	int packer_num = 0;
	
	for(int i = 0; i < NUM_PACKERS; ++i){
		if (all_packers[i].wait_time() < temp_wait){
			packer_num = i;
		}
	}
	//cout << "check 8 \n" << endl;//DEBUG
	//cout << "packer_num: " << packer_num << endl;//DEBUG
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
		cout << "all_packers[" << i<< "].wait_time(): " << all_packers[i].wait_time() << endl << endl;
	}
}

void Pack_Boss::increment_time()
{
	//cout << "check 6 \n" << endl;//DEBUG
	for (int i = 0; i < NUM_PACKERS; ++i){
		all_packers[i].increment_time();
	}
}
