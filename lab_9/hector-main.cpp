#include <iostream>
#include <stdio.h>
#include "hector.h"

using namespace std;
//
// hector-main.cpp -- tests the three versions with sample data
//
int main() 
{
	
	void test_with(string, int[]);

	int randomInserts[] = {	16807, 284249, 1603, 98438,
				1144130, 471272, 127544, 1450878,
				148723, 207709, SENTINEL };
	
	int notRandom1[] = { 3, 20, 37, 21, 4, 5, 7, 23, 2, 0, SENTINEL};
	
	int notRandom2[] = { 3, 9, 15, 20, 26, 32, 37, 43, 49, 0, SENTINEL};

	test_with("Test One",   randomInserts);
	test_with("Test Two",   notRandom1);
	test_with("Test Three", notRandom2);
	
	return 0;
}
//
// test the class with an array of ints
//  Does: insert the data, keep stats
//  then: report results, print the hash tables
//
void test_with(string title, int data[])
{
	Hector	h;
	
	int maxL = 0;
	int maxD = 0;
	int maxC = 0;
	int sumL = 0;
	int sumD = 0;
	int colls;
	int i;
	
	cout << title << endl;
	cout << "inserting keys:";
	for(i=0; data[i] != SENTINEL ; i++)
	{
		cout << " " << data[i];
		colls = h.linny(data[i]);
		sumL += colls;
		if ( colls > maxL ) maxL = colls;

		colls = h.doubles(data[i]);
		sumD += colls;
		if ( colls > maxD ) maxD = colls;

		colls = h.cheney(data[i]);
		if ( colls > maxC ) maxC = colls;
	}
	cout << endl << "results:" << endl;

	printf("     linny: reprobes = %d  max lookup = %d\n", sumL, maxL);
	printf("   doubles: reprobes = %d  max lookup = %d\n", sumD, maxD);
	printf("    cheney: reprobes = 0  max bucket size= %d\n",    maxD+1);
	cout << endl;
	cout << "The tables:" << endl;

	h.print();
	cout << endl;
}
