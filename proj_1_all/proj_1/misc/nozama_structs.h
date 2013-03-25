//Created by: Cameron Barclift

#ifndef nozama_structs.h
#define

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

//report sent from the packager to the manager
struct Packing_Report
{
	bool package_out;
	Order order_packed;	

}

//struct to hold data in a linked list queue
struct Queue_Node
{
	Order data;
	Order* next;
	Order* prev;
};

#endif