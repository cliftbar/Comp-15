#include <iostream>
#include "TOT.h"
#include "TTEST.h"


using namespace std;


int main()
{
    //create a test suite
    TTest test;
    
    
    //load trancsripts from file
    //into the test suite
    test.loadTranscripts();
    
    //get amount of trancsripts read
    int testListSize = test.getTranscriptCount();
    
    //get list of trancsripts read
    Transcript* testList = test.getTranscriptList();
    
    //get list of student ids read
    string* testStudentIDs = test.getStudentIDs();
    
    
    //use list of transcripts and size to
    //initialize Tufts Online Transcripts
    TOT testToT(testList, testListSize);
    
    //create a dynamic array of transcript
    //pointers to hold all of the copys
    Transcript** storedInToT = new Transcript*[testListSize];
    
    //now populuate that list using the copy function
    for (int i = 0; i < testListSize; i++)
    {
        storedInToT[i] = testToT.getTranscriptCopy(testStudentIDs[i]);
        
    }
    
    //print that list using the test class
    //this is a bit cumbersome, but was done to
    //hide the answer
    
    test.printTranscript(storedInToT, testListSize);
    
    
    
    
    
}

