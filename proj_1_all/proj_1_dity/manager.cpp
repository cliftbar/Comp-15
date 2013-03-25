//manager.cpp
//Created by: Cameron Barclift
//Creates the input buffer, then runs the two simulations.
//Mainly just a wrapper for the simulations and buffer.
#include <iostream>
#include "manager.h"

using namespace std;

Manager::Manager()
{
	//default constructor
}

void Manager::run_simulations()
{
	Buffer sales;
	Stats sim_1_stats(false);
	Stats sim_2_stats(true);
	
	sales.read_in();
	Queue* temp_queue;
	
	//sales.print_orders();//DEBUG CODE
	
	Simulation sim_1(false, sales.pass_queue());
	temp_queue = sim_1.run_sim();
	
	
	temp_queue = unscramble_queue(temp_queue);
	cout << "unscramble_queue: " << endl;
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
	cout << "check A\n";
	Queue* sort_queue = new Queue;
	Node* head = NULL;
	Node* prev = NULL;
	Node* temp = NULL;
	Node* iter = NULL;
		
	if (q_in == NULL){
		cout << "check B\n";
		return q_in;
	}
	
	cout << "check C\n";
	while (!q_in->is_empty()){
		cout << "check D\n";
		temp = new Node;
		temp->data = q_in->remove();
		temp->next = NULL;
		iter = head;
		
		if (head == NULL){
			cout << "check E\n";
			head = temp;
			prev = temp;
		}else if (iter->data.t_arrive > temp->data.t_arrive){
			cout << "check F\n";
			temp->next = iter;
			head = temp;
			prev = temp;
		}else {
			cout << "check G\n";
			while(iter->next != NULL && iter->data.t_arrive < temp->data.t_arrive){
				cout << "check H\n";
				prev = iter;
				iter = iter->next;
			}
			if (iter->next == NULL && iter->data.t_arrive < temp->data.t_arrive){
				cout << "check I\n";
				prev = iter;
				iter->next = temp;
			}else {
				cout << "check J\n";
				temp->next = iter;
				prev->next = temp;
			}
		}
	}
	
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
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
