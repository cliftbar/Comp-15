//pack_boss.h
//Created by: Cameron Barclift
//Pack_Boss class holds a dynamic array of packers, the number of which is
//is set by the constant NUM_PACKERS, set in the constructor.

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
	
	//takes in an order and stores it
	void pass_in(Order o_in);
	
	//returns the number of orders ready from all the packers 
	int num_orders_up();
	
	//returns an order, cannot be called if no orders are ready
	Order pass_out();
	
	//returns whether all of the packers in the array are done
	bool all_done();
	
	void print_packers();
	
	void increment_time();
private:
	//returns the shortest queue of all of the packers
	int find_shortest(bool supreme);
	
	//returns if all of the queues have a supreme order
	bool all_supreme();
	
	//sets the initial wait time for find shortest function
	void set_init_temp_wait(bool supreme);
	
	//logic to find the shortest queue if all queues have a supreme order
	int f_short_all_supreme(bool supreme, int i);
	
	//logic to find the shortest queue if not all queues have a supreme order
	int f_short_not_all_supreme(bool supreme, int i);
	
	//logic to find the shortest queue if the order is supreme
	int f_shortest_supreme(bool supreme);
	
	//logic to find the shortest queue if the order is regular
	int f_shortest_regular(bool supreme);
	
	//Pointer to an array of packers
	Packer* all_packers;
	
	int NUM_PACKERS;
	
	//holds if the packers are done
	bool packers_done;
	
	//hold value to find shortest queue
	int temp_wait;
	
	//wait time variable used specifically for the case when
	//multiple supreme queues have the same supreme wait time
	int special_reg_wait;

};


#endif
