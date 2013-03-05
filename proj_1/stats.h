
#ifndef STATS
#define STATS
#include <iostream>
#include "order.h"
#include "queue.h"

using namespace std;

class Stats
{
public:
	Stats(bool consider_supreme);
	void get_order(Order o_in);
	void run_calcs();
	Order return_order();
	void print_stats();
	
private:
	void calc_min_max();
	void calc_means();
	void calc_mean_regular();
	void calc_mean_supreme();
	void calc_mean_all();
	
	Order curr_order;
	bool first_order;
	bool supreme;
	int sim_num;
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