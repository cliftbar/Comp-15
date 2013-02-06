//Created by: Cameron Barclift
//main.cpp file for homework 1
//runs tests on TOT2.cpp
//reads in a studenID from the stream and prints the requested transcript,
//or an error if the transcript is not there.

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
	
	/*//function to print provided transcript list, uncomment to use
	for (int i = 0; i < tsNum; ++i){
		my_system.transcript_list_print(&(tsList[i]));
	}//*/
	
	cout << "Enter a student ID to retrieve a transcript.\n";
	cin >> student_ID;
	
	tran_copy = my_system.getTranscriptCopy(student_ID);
	if (tran_copy != NULL){
		my_system.transcript_list_print(tran_copy);
	}else if (tran_copy == NULL){
		cout << "transcript not found.\n";
	}
	
}