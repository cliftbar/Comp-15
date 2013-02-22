//Created by: Cameron Barclift

#ifndef queue.h
#define
#include <iostream>
#include <cstdlib>
#include <string>
#include queue_node

//creates a queue
class Queue
{
public:
	void insert();
	Order remove();
	bool is_empty();
	int length();
	
	
private:
	Order* head;
	Order* prev;
	Order* tail;
	int length();
	
}

#endif