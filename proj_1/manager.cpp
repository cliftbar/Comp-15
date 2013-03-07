//manager.cpp
//Created by: Cameron Barclift
//Creates the input buffer, then runs the two simulations.
//Mainly just a wrapper for the simulations and buffer.
#include <iostream>
#include "manager.h"

using namespace std;

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
	Stats sim_1_stats(false);
	Stats sim_2_stats(true);
	
	sales.read_in();
	Queue* temp_queue;
	
	
	Simulation sim_1(false, sales.pass_queue());
	temp_queue = sim_1.run_sim();
	
	
	temp_queue = unscramble_queue(temp_queue);
	temp_queue->print_queue();
	
	Simulation sim_2(true, temp_queue);
	temp_queue = sim_2.run_sim();
	
	for (int i = 0; i < temp_queue->get_length(); ++i){
		sim_1_stats.get_order(temp_queue->remove());
		sim_1_stats.run_calcs();
		sim_2_stats.get_order(sim_1_stats.return_order());
		sim_2_stats.run_calcs();
		temp_queue->insert(sim_2_stats.return_order());
	}
	
	temp_queue->print_queue();
	
	sim_1_stats.print_stats();
	sim_2_stats.print_stats();
}

Queue* Manager::unscramble_queue(Queue* q_in)
{
	if (q_in == NULL){
		return q_in;
	}
	
	unscramble_insert(q_in);
	
	iter = head;
	
	while (iter != NULL){
		cout << "check K\n";
		temp = iter;
		sort_queue->insert(temp->data);
		iter = iter->next;
		delete temp;
	}
	
	cout << "check L\n";
	return sort_queue;
}
			
void Manager::unscramble_insert(Queue* q_in)
{
	while (!q_in->is_empty()){
		temp = new Node;
		temp->data = q_in->remove();
		temp->next = NULL;
		iter = head;
		
		if (head == NULL){
			head = temp;
			prev = temp;
		}else if (iter->data.t_arrive > temp->data.t_arrive){
			temp->next = iter;
			head = temp;
			prev = temp;
		}else {
			while(iter->next != NULL && iter->data.t_arrive < temp->data.t_arrive){
				prev = iter;
				iter = iter->next;
			}
			if (iter->next == NULL && iter->data.t_arrive < temp->data.t_arrive){
				prev = iter;
				iter->next = temp;
			}else {
				temp->next = iter;
				prev->next = temp;
			}
		}
	}
}
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
