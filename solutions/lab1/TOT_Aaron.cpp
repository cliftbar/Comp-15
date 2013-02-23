/*
	TOT_solution.cpp
	Aaron Tietz
	Comp 15, Spring 2013
	Lab 1 solution
*/

#include "TOT_Aaron.h"
#include <cstdlib>

TOT::TOT(){
  currentTranscriptCount = 0;
}
    
    //constructor given a list (dynamic array) of trancsripts
    //of size listSize copies this list of
    //transcripts into the system
TOT::TOT(Transcript* transcriptList, int listSize){
  if(listSize > MAX_SIZE){
    cerr << "not enough room\n";
    exit(1);
  }
  currentTranscriptCount = listSize;
  Transcript* temp;
  for(int i = 0; i < listSize; i++){
    temp = makeTranscriptCopy(&transcriptList[i]);
    transcripts[i] = temp;
    }
}    

    //return a pointer to a new transcript with data
    //from transcript list, it does not point to stored
    //data.
Transcript* TOT::getTranscriptCopy(string studentID){
  Transcript* temp = lookUp(studentID);
  return makeTranscriptCopy(temp);
  
/*
    This works because lookUp returns NULL if not found, 
    and makeTranscriptCopy returns NULL if passed a NULL*.
*/
}


Transcript* TOT::lookUp(string sID){
  int i = 0;
  while (i < MAX_SIZE && (transcripts[i]->studentID != sID ))
    i++;
        
  if (i < MAX_SIZE)
    return transcripts[i];

  return NULL;
}

    // takes a pointer to a Transcript and returns a pointer to a copy of it
Transcript* TOT::makeTranscriptCopy(Transcript* copyFrom){
  if (copyFrom == NULL) 
    return NULL;
  Transcript* temp = new Transcript;
  *temp = *copyFrom; // copy all non pointer vars safely
  int sems = temp->numberOfSemesters;
  int courses;
  temp->semesters = new Semester[sems];  // then deep copy the array
  for(int i = 0; i < sems; i++){
    temp->semesters[i] = copyFrom->semesters[i]; // copy all non pointer vars safely
    courses = temp->semesters[i].numberOfCourses;
    temp->semesters[i].courses = new Course[courses]; // then deep copy the array 
    for(int j = 0; j < courses; j++){
      temp->semesters[i].courses[j] = copyFrom->semesters[i].courses[j]; // copy non pointer vars
    }
  }
  return temp;
}
