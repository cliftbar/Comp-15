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
	Queue* run_stats(Queue* temp_queue);
	void unscramble_insert(Queue* q_in);
	
	Stats* sim_1_stats;
	Stats* sim_2_stats;
	Queue* sort_queue;
	Node* head;
	Node* prev;
	Node* temp;
	Node* iter;
	Queue* temp_queue;
};

#endif
