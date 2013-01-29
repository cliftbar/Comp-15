#ifndef TEST_H
#define TEST_H

#include <iostream>
#include "Transcript.h"

//Hidden class to test lab code
class TTest
{

public:
    
    //constructor set values
    TTest();
    
    //load a set of trancsripts
    //from standard in
    void loadTranscripts();

    //return loaded trancsript list
    Transcript* getTranscriptList();
    
    int getTranscriptCount();
    
    //get list of studentIDs loaded
    string* getStudentIDs();
    
    void printTranscript(Transcript** stored, int size);
    
private:
 
    Transcript* transcripts;
    int transcriptCount;
    
    
};


#endif

