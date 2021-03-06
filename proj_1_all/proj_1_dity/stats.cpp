
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

#include "stats.h"
using namespace std;

//////////////////////PUBLIC METHODS////////////////////////////////////

Stats::Stats(bool consider_supreme)
{
	//cout << "consider_supreme: " << consider_supreme << endl;//DEBUG CODE
	//Sets what number simulation it is
	if (consider_supreme){
		sim_num = 2;
	}else if (!consider_supreme){
		sim_num = 1;
	}
	supreme = consider_supreme;
	
	//sim_num = 1;//DEBUG CODE;
	sim_max = 0;
	sim_min = 0;
	mean_reg = 0;
	mean_sup = 0;
	mean_all = 0;
	first_order = true;
	num_reg_processed = 0;
	num_sup_processed = 0;
	num_all_processed = 0;
}
void Stats::get_order(Order o_in)
{
	//if the first order is read in, initialize sim_max and sim_min
	if (first_order){
		//cout << "check first" << endl;//DEBUG CODE
		if(supreme){
			sim_max = o_in.t_out_sim2;
			sim_min = o_in.t_out_sim2;
		}else if (!supreme){
			sim_max = o_in.t_out_sim1;
			sim_min = o_in.t_out_sim1;
		}
		first_order = false;
	}
	
	curr_order = o_in;
}

void Stats::run_calcs()
{
	//decides which order time to send to the calculation functions,
	//sim 1 time or sim 2 time
	if (supreme){
		cout << "current order time sim 2: "
			<< curr_order.t_out_sim2 << endl;
		calc_min_max(curr_order.t_out_sim2);
		calc_means(curr_order.t_out_sim2);
	}else if(!supreme){
		calc_min_max(curr_order.t_out_sim1);
		calc_means(curr_order.t_out_sim1);
	}
}

Order Stats::return_order()
{
	return curr_order;
}

void Stats::print_stats()
{
	cout << "sim" << sim_num << " min elapsed time " << sim_min << " minutes"
		<< endl;
	cout << "sim" << sim_num << " max elapsed time " << sim_max << " minutes"
		<< endl;
	if (!supreme){
		cout << "sim" << sim_num << " mean elapsed time " << (int)mean_all
			<< " minutes" << endl;
	}else if(supreme){
		cout << "sim" << sim_num << " mean total time for all customers "
			<< int(mean_all) << " minutes" << endl;
		cout << "sim" << sim_num << " mean total time for supreme customers "
			<< int(mean_sup) << " minutes" << endl;
		cout << "sim" << sim_num << " mean total time for regular customers "
			<< (int)mean_reg << " minutes" << endl;
	}
	cout << num_all_processed << " orders processed" << endl << endl;
}

////////////////////////////PRIVATE METHODS///////////////////////////////

void Stats::calc_min_max(int t_comp)
{
	//cout << "current order time: " << curr_order.t_out;//DEBUG CODE
	//if the total time passed in is a min or max, it is stored
	if (t_comp < sim_min){
		//cout << " is a min" << endl;//DEBUG CODE
		sim_min = t_comp;
	}else if (t_comp > sim_max){
		//cout << " is a max" << endl;//DEBUG CODE
		sim_max = t_comp;
	}
}

//Mean calculation functions below
void Stats::calc_means(int t_in)
{
	if (curr_order.priority == "regular"){
		calc_mean_regular(t_in);
	} else if (curr_order.priority == "supreme"){
		calc_mean_supreme(t_in);
	}
	calc_mean_all(t_in);
	
}

void Stats::calc_mean_regular(int t_comp)
{
	double temp = mean_reg;
	temp = mean_reg * num_reg_processed;
	temp += t_comp;
	++num_reg_processed;
	mean_reg = (temp / num_reg_processed);
}

void Stats::calc_mean_supreme(int t_comp)
{
	double temp = mean_sup;
	temp = mean_sup * num_sup_processed;
	temp += t_comp;
	++num_sup_processed;
	mean_sup = (temp / num_sup_processed);
}

void Stats::calc_mean_all(int t_comp)
{
	double temp = mean_all;
	temp = mean_all * num_all_processed;
	temp += t_comp;
	++num_all_processed;
	mean_all = (temp / num_all_processed);
}
