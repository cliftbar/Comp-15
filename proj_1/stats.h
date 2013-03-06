
//stats.h
//Created by: Cameron Barclift
//Class used to calculate statistics for the simulation.
//Values calculated:
//	total number of orders processed
//	minumum time spent in the simulation
//	maximum time spent in the simulation
//	mean time spent in simulation for all customers
//	mean time spent in simulation for regular customers
//	mean time spent in simulation for supreme customers

#ifndef STATS
#define STATS
#include <iostream>
#include "order.h"
#include "queue.h"

using namespace std;

class Stats
{
public:
	//Constructor, takes in whether to consider supreme orders or not
	Stats(bool consider_supreme);
	
	//Take in order
	void get_order(Order o_in);
	
	//Runs all required calculations
	void run_calcs();
	
	//returns the current order
	Order return_order();
	
	//prints a report of the statistics calculations
	void print_stats();
	
private:
	//determines if the current order is a min or max time
	void calc_min_max(int t_comp);
	
	//calls the functions to determine the mean values for
	//the simulation.
	void calc_means(int t_in);
	
	//Functions for calculating the required mean values
	void calc_mean_regular(int t_comp);
	void calc_mean_supreme(int t_comp);
	void calc_mean_all(int t_comp);
	
	Order curr_order;
	
	//Tracks whether the order passed in is the first order
	//for initialization of sim_max and sim_min.
	bool first_order;
	
	//Holds whether to consider supreme orders or not
	//True: consider supreme orders
	//False: don't consider supreme orders
	bool supreme;
	
	//holds the number of the simulation being run 
	int sim_num;
	
	//calculation values
	int sim_max;
	int sim_min;
	double mean_reg;
	double mean_sup;
	double mean_all;
	int num_reg_processed;
	int num_sup_processed;
	int num_all_processed;
};

#endif
