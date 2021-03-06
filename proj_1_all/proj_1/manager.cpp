
//manager.cpp
//Created by: Cameron Barclift
//Creates the input buffer, then runs the two simulations, then calulates
//the statistics, then prints the output

#include <iostream>
#include "manager.h"

using namespace std;

/////////////////////////Publics Methods////////////////////////////////

Manager::Manager()
{
	sort_queue = new Queue;
	head = NULL;
	prev = NULL;
	temp = NULL;
	iter = NULL;
}

void Manager::run_simulations()
{
	Buffer sales;
	sim_1_stats = new Stats(false);
	sim_2_stats = new Stats(true);
	
	sales.read_in();
	
	//run sim 1
	Simulation sim_1(false, sales.pass_queue());
	temp_queue = sim_1.run_sim();
	
	//reoder queue
	temp_queue = unscramble_queue(temp_queue);
	
	//run sim 2
	Simulation sim_2(true, temp_queue);
	temp_queue = sim_2.run_sim();
	
	//run statisctics
	temp_queue = run_stats(temp_queue);
	
	//print results, with extra lines to match output formatting
	temp_queue->print_queue();
	cout << endl;
	sim_1_stats->print_stats();
	cout << endl;
	sim_2_stats->print_stats();
}

/////////////////////////Private Methods////////////////////////////////


//Resorts the orders, earliest arrival time first
Queue* Manager::unscramble_queue(Queue* q_in)
{
	if (q_in == NULL){
		return q_in;
	}
	
	unscramble_insert(q_in);
	
	iter = head;
	
	//inserts the sorted linked list into the queue
	while (iter != NULL){
		temp = iter;
		sort_queue->insert(temp->data);
		iter = iter->next;
		delete temp;
	}
	
	return sort_queue;
}

//inserts the queue into a sorted linked list implementation
void Manager::unscramble_insert(Queue* q_in)
{
	while (!q_in->is_empty()){
		temp = new Node;
		temp->data = q_in->remove();
		temp->next = NULL;
		iter = head;
		
		if (head == NULL){
			//Empty list
			head = temp;
			prev = temp;
		}else if (iter->data.t_arrive > temp->data.t_arrive){
			//new node goes into first slot
			temp->next = iter;
			head = temp;
			prev = temp;
		}else {
			while(iter->next != NULL &&
				 iter->data.t_arrive < temp->data.t_arrive){
				//finds place to put new node
				prev = iter;
				iter = iter->next;
			}
			if (iter->next == NULL &&
			    iter->data.t_arrive < temp->data.t_arrive){
				//node goes in front of iter
				prev = iter;
				iter->next = temp;
			}else {
				//node goes behind iter, at the end of the list
				temp->next = iter;
				prev->next = temp;
			}
		}
	}
}

//runs the statisctics on the queue for both simulations
Queue* Manager::run_stats(Queue* temp_queue)
{
	for (int i = 0; i < temp_queue->get_length(); ++i){
		sim_1_stats->get_order(temp_queue->remove());
		sim_1_stats->run_calcs();
		sim_2_stats->get_order(sim_1_stats->return_order());
		sim_2_stats->run_calcs();
		temp_queue->insert(sim_2_stats->return_order());
	}
	
	return temp_queue;
}
