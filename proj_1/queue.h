//Created by: Cameron Barclift

#ifndef QUEUE
#define QUEUE
#include <iostream>
#include <cstdlib>
#include <string>
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
	Queue();
	Queue(const Queue &rhs);
	bool is_empty();
	void insert(const Order to_add);
	Order remove();
	int get_length();
	void print_queue();
	int t_next();
	
private:
	Node* front;
	Node* back;
	int length;
	
};

#endif