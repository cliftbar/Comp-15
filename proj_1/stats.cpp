
#include "stats.h"
using namespace std;

Stats::Stats(bool consider_supreme)
{
	//cout << "consider_supreme: " << consider_supreme << endl;//DEBUG CODE
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
	if (first_order){
		//cout << "check first" << endl;//DEBUG CODE
		sim_max = o_in.t_out;
		sim_min = o_in.t_out;
		first_order = false;
	}
	
	curr_order = o_in;
}

void Stats::run_calcs()
{
	calc_min_max();
	calc_means();
}

Order Stats::return_order()
{
	return curr_order;
}

void Stats::print_stats()
{
	int print_mean_reg = mean_reg;
	int print_mean_sup = mean_sup;
	int print_mean_all = mean_all;
	
	cout << "sim" << sim_num << " min elapsed time " << sim_min << " minutes" << endl;
	cout << "sim" << sim_num << " max elapsed time " << sim_max << " minutes" << endl;
	if (!supreme){
		cout << "sim" << sim_num << " mean elapsed time " << print_mean_all << " minutes" << endl;
	}else if(supreme){
		cout << "sim" << sim_num << " mean total time for all customers " << print_mean_all << " minutes" << endl;
		cout << "sim" << sim_num << " mean total time for supreme customers " << print_mean_sup << " minutes" << endl;
		cout << "sim" << sim_num << " mean total time for regular customers " << print_mean_reg << " minutes" << endl;
	}
	cout << num_all_processed << " orders processed" << endl << endl;
}

void Stats::calc_min_max()
{
	//cout << "current order time: " << curr_order.t_out;//DEBUG CODE
	
	if (curr_order.t_out < sim_min){
		//cout << " is a min" << endl;//DEBUG CODE
		sim_min = curr_order.t_out;
	}else if (curr_order.t_out > sim_max){
		//cout << " is a max" << endl;//DEBUG CODE
		sim_max = curr_order.t_out;
	}
}
	

void Stats::calc_means()
{
	//add in sim if here
	if (curr_order.priority == "regular"){
		calc_mean_regular();
	} else if (curr_order.priority == "supreme"){
		calc_mean_supreme();
	}
	calc_mean_all();
	
}
void Stats::calc_mean_regular()
{
	double temp = mean_reg;
	temp = mean_reg * num_reg_processed;
	temp += curr_order.t_out;
	++num_reg_processed;
	mean_reg = (temp / num_reg_processed);
}

void Stats::calc_mean_supreme()
{
	double temp = mean_sup;
	temp = mean_sup * num_sup_processed;
	temp += curr_order.t_out;
	++num_sup_processed;
	mean_sup = (temp / num_sup_processed);
}

void Stats::calc_mean_all()
{
	double temp = mean_all;
	temp = mean_all * num_all_processed;
	temp += curr_order.t_out;
	++num_all_processed;
	mean_all = (temp / num_all_processed);
}