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
};

#endif
