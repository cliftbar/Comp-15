#ifndef TOT2_H
#define TOT2_H


#include <iostream>
#include "Transcript.h"

using namespace std;

//initial size of dynamic array
const int INIT_SIZE = 5;

//factor to increase the size of array, we double every time we expand the array
const int RESIZE_FACTOR = 2;

class TOT2
{
    public:

        //constructor creates dynamic array of size INIT_SIZE, sets pointers to NULL

        TOT2();

        //same constructor as before, note you may call addTranscript function
        TOT2(Transcript* transcriptList, int listSize);

        //same function as before
        Transcript* getTranscriptCopy(string studentID);

        //new function add a single Transcript to the system, returns bool if it worked
        bool addTranscript(Transcript* t);

    private:
    
        //dynamic array of pointers to Transcripts
        Transcript** transcripts;

        Transcript* lookUp(string sID);

        //new function to expand dynamic array when it is full
        void expand();

        //count of how many currently stored
        int currentCount;

        //capacity of the dynamic ray
        int currentCapacity;

};


#endif

