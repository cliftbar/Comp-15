Nozama README
Project 1, Nozama simulation
Created by: Cameron Barclift

Program is a simulator of warehouse operations for nozama.  It runs two
packing simulations: the first does not consider whether an order belongs
to a supreme customer, the second allows supreme customers to jump ahead
of regular customers in the packing queue.

Notes:
The file is read into a buffer once, using standard input
The input is a formatted list of orders, arranged by arrival time.
The orders are output in the order that they leave simulation 2.
Manager class is the only class used in main, it handles everything else.
Three packers are used.  To change the number of packers, change
	the variable NUM_PACKERS in pack_boss.cpp

A shell script is provided to compile the program, using g++ and compiling
	to a.out, use the terminal command

	sh compile_proj1

compile_proj1 runs this command

	g++ -g -Wall -Wextra queue.cpp packer.cpp pack_boss.cpp simulation.cpp
		main.cpp front.cpp fetcher.cpp buffer.cpp stats.cpp manager.cpp



List of header files (10 files):
buffer.h
fetcher.h
front.h
manager.h
order.h
pack_boss.h
packer.h
queue.h
simulation.h
stats.h

List of cpp files (10):
buffer.cpp
fetcher.cpp
front.cpp
main.cpp
manager.cpp
pack_boss.cpp
packer.cpp
queue.cpp
simulation.cpp
stats.cpp

List of other files:
compile_proj1
README