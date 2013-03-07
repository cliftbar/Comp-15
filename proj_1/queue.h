//queue.h
//Created by: Cameron Barclift
//implements a queue of orders, fifo

#ifndef QUEUE
#define QUEUE
#include <iostream>
#include <cstdlib>
#include "order.h"

using namespace std;

//struct to hold data in a linked list queue
struct Node
{
	Order data;
	Node* next;
};

//creates a queue
class Queue
{
public:
	//constructor
	Queue();
	
	//copy constructor
	Queue(const Queue &rhs);
	
	//True: queue is empty
	//False: queue is not empty
	bool is_empty();
	
	void insert(const Order to_add);
	
	//cannot handle an empty queue, program terminates
	Order remove();
	
	int get_length();
	
	void print_queue();
	
	//returns the arrival time of the next order in the queue
	int t_next();
	
private:
	//copies a list passed in
	void copy_in_list(Node* f_other);
	
	Node* front;
	
	Node* back;
	
	int length;
};

#endif
