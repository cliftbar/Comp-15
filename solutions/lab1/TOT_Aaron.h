/*
	TOT_solution.h
	Aaron Tietz
	Comp 15, Spring 2013
	Lab 1 solution
*/

#ifndef TOT_H
#define TOT_H


#include <iostream>
#include "Transcript.h"

using namespace std;

//we are starting with
//just a static array of Transcript*
//we will update in a future assignment
const int MAX_SIZE = 10;


class TOT
{
    
    public:
    
    
    //default constructor sets the count to zero
    TOT();
    
  
    
    //constructor given a list (dynamic array) of trancsripts
    //of size listSize copies this list of
    //transcripts into the system
    TOT(Transcript* transcriptList, int listSize);

    
    //return a pointer to a new transcript with data
    //from transcript list, it does not point to stored
    //data.
    Transcript* getTranscriptCopy(string studentID);
    
    private:
    // a private helper function I declared to use in my public functions
    Transcript* makeTranscriptCopy(Transcript* copyFrom);
    
    //static array of pointers to Transcripts
    Transcript* transcripts[MAX_SIZE];
    
    Transcript* lookUp(string sID);
    
    //count of how many
    int currentTranscriptCount;
    
};

#endif
