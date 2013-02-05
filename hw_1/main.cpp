//main.cpp file for homework 1
#include <iostream>
#include "TOT2.h"
#include "TestDat.h"

using namespace std;

int main()
{	
	Transcript* tran_copy;
	string student_ID;
	
	//use list of transcripts and size to
	//initialize Tufts Online Transcripts
	TOT2 my_system(tsList, tsNum);
	
	cout << "Enter a student ID to retrieve a transcript.\n";
	cin >> student_ID;
	
	tran_copy = my_system.getTranscriptCopy(student_ID);
	cout << "tran_copy->student_ID: " << tran_copy->studentID << endl;
	
}