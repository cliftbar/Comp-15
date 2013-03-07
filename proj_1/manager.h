//manager.h
//Created by: Cameron Barclift

#ifndef MANGER
#define MANAGER
#include <iostream>
#include "buffer.h"
#include "simulation.h"

using namespace std;

class Manager
{
public:
	//default constructor, does nothing on purpose
	Manager();
	
	//runs both simulations
	void run_simulations();
	
	Queue* unscramble_queue(Queue* q_in);
	
private:
	void unscramble_insert(Queue* q_in);
	Queue* sort_queue;
	Node* head;
	Node* prev;
	Node* temp;
	Node* iter;
};

#endif
