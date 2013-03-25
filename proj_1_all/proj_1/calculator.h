//Created by: Cameron Barclift

#ifndef calculator.h
#define
#include <iostream>
#include <cstdlib>
#include <string>

class calculator_jockey
{
public:
	//Calculates the various required calculations
	void run_calcs();
	//prints the results
	void print_calcs();
private:
	int min_time;
	int max_time;
	int mean_all;
	int mean_supreme;
	int mean_regular;
	int num_orders;
};

#endif