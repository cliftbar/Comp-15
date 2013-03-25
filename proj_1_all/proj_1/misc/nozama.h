
#ifndef nozama.h
#define
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std

struct Order
{
	//Unique ID number
	int id;
	//Arrival Time
	int t_arrive;
	//How long after arrival time it takes
	//to find and load into a packing unit
	int t_fetch;
	//How long it takes to get packaged
	int t_pack;
	//determines packaging priority
	string priority;
};

struct Packing_Report
{
	bool package_out;
	Order order_packed;	

struct Queue_Node
{
	Order data;
	Order* next;
	Order* prev;
};

class Fetching_Unit
{
public:
	//default constructor
	Fetching_Unit();
	//picks up order
	void get_order(Order order_in);
	//passes order to packer
	Order deliver_order();
	//determines if the fetching unit is free,
	bool unit_free();
	bool order_ready();
private:
	//Passes the order to the indicated unit
	void choose_queue(Packing_Unit* pass_to);
	//holds the current order
	Order curr_order;
	//increments the internal time and
	//the time of held order, also updates the
	//queue time
	void increment_time();
	//holds the current fetch time,
	//resets to zero after every order
	int curr_time;
	//holds status of unit, free or not free
	bool unit_status;
};

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

class calculator_jockey
{
public:
	//Calculates the various required calculations
	void run_calcs();
	//prints the results
	void print_calcs();
private:
	int min_time;
	int max_time;
	int mean_all;
	int mean_supreme;
	int mean_regular;
	int num_orders;
};

//coordinates warehouse floor activities
class Manager
{
public:
	//runs all of the functions required for
	//a time interval on the floor
	void run_floor();
	//Prints the final report on floor activities
	void report();
private:
	//increments the time forward one unit
	void increment_time();
	//determines the shortest queue among
	//the available packers
	void shortest_queue();
	
	//array of pointers to fetchers,
	//array is static
	Fetching_Unit* fetchers[NUM_FETCHERS];
	//array of pointers to packers,
	//array is static
	Packing_Unit* packers[NUM_PACKERS];
	//holds a pointer to the packer with the shortest queue
	Packing_Unit* next_packer;
	//master time for the simulation
	int absolute_time;
	
};

#endif
