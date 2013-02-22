//Created by: Cameron Barclift

#ifndef packer.h
#define
#include <iostream>
#include <cstdlib>
#include <string>
#include "packing_report"
#include "queue"
#include "order"

class Packing_Unit
{
public:
	//returns the queue length
	int queue_length();
	//adds an order to the queue
	void add_to_queue(Order o_add);
	//asks if the packing on the current order is done,
	//if it is, a packing report is printed
	bool packing_done();
private:
	//checks if the order added is supreme or not
	void is_supreme();
	//Prints the packing report for the current order
	void packing_report();
	//contains the order currently being packed
	Order* curr_order;
	//holds the start of the queue
	Order* queue_start;
	//holds the current packing time,
	//resets to zero after every order.
	int curr_time;
	//store the time of an order on hold
	int t_hold;
	//time required for all items in the queue
	int queue_time;
};

#endif