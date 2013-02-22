//Created by: Cameron Barclift

#ifndef front.h
#define
#include <iostream>
#include <cstdlib>
#include <string>
#include "order"

//Takes in orders and maintains the order queue
class front_desk
{
public:
	//Reads in the order from stream
	void read_in_order();
	//Asks if there is an order in the queue
	bool is_order();
	//Passes an order from the queue
	//Does not check if there is an order or not
	Order pass_order();
	
private:
	//adds an order to the queue
	void add_to_queue();
	//orders read in by front_desk
	Node* order_queue;
};

#endif