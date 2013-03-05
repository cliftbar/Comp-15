//pack_boss.h

#ifndef PACK_BOSS
#define PACK_BOSS
#include <iostream>
#include <cstdlib>
#include "order.h"
#include "queue.h"
#include "packer.h"

using namespace std;

class Pack_Boss
{
public:
	Pack_Boss();
	
	void consider_supreme(bool do_supreme);
	
	void pass_in(Order o_in);
	
	int num_orders_up();
	
	Order pass_out();
	
	bool all_done();
	
	void print_packers();
	
	void increment_time();
	
private:
	int find_shortest(bool supreme);
	
	bool all_supreme();
	
	Packer* all_packers;
	
	int NUM_PACKERS;
	
	bool packers_done;
	
	bool supreme;
};


#endif
