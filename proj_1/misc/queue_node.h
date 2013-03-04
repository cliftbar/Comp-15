//Created by: Cameron Barclift

#ifndef queue_node.h
#define
#include <iostream>
#include <cstdlib>
#include <string>
#include "order"

using namespace std

//struct to hold data in a linked list queue
struct Queue_Node
{
	Order data;
	Order* next;
	Order* prev;
};

#endif