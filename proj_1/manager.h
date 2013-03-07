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
	//default constructor
	Manager();
	
	//runs both simulations
	void run_simulations();
	
	//reorder queue based on arrival time
	Queue* unscramble_queue(Queue* q_in);
private:
	Queue* run_stats(Queue* temp_queue);
	
	//insert into sorted linked list implementation
	void unscramble_insert(Queue* q_in);
	
	Stats* sim_1_stats;
	Stats* sim_2_stats;
	Queue* temp_queue;
	
	//linked list implementation variables
	Queue* sort_queue;
	Node* head;
	Node* prev;
	Node* temp;
	Node* iter;
	
};

#endif
