//TOT2.cpp file for homework 1

#include "TOT2.h"

TOT2::TOT2()
{
	currentCount = 0
	currentCapacity = INIT_SIZE;
}

TOT2::TOT2(Transcript* transcriptList, int listSize)
{	
	currentCount = 0
	currentCapacity = INIT_SIZE;
	transcripts = new Transcript*[currentCapacity]
	
	for (int i = 0; i < listSize; ++i){
		transcripts[i] = new Transcript;
		transcripts[i]->studentID = transcriptList[i].studentID;
		transcripts[i]->numberOfSemesters = transcriptList[i].numberOfSemesters;
		for (int j = 0; j < transcripts[i]->numberOfSemesters; ++j){
			transcripts[i]->semesters = new Semester;
			transcripts[i]->semesters[j].term = transcriptList[i].semesters[j].term;
			transcripts[i]->semesters[j].year = transcriptList[i].semesters[j].year;
			transcripts[i]->semesters[j].numberOfCourses = transcriptList[i].semesters[j].numberOfCourses;
			for (int k = 0; k < transcriptList[i].semesters[j].numberOfCourses; ++k){
				transcripts[i]->semesters[j].courses = new Course;
				transcripts[i]->semesters[j].courses[k].courseNumber = transcriptList[i].semesters[j].courses[k].courseNumber;
				transcripts[i]->semesters[j].courses[k].grade = transcriptList[i].semesters[j].courses[k].grade;
			}
		}
	}
}

void TOT2::expand()
{
	Transcript** temp = NULL;
	temp = new Transcript*[currentCount * RESIZE_FACTOR];
	
	for (int i = 0; i < currentCount; ++i){
		temp[i] = transcripts[i];
	}
	
	delete transcripts;
	
	transcripts = temp;
	temp = NULL;
}
bool addTranscript(Transcript* t)
{
	if (currentCount == currentCapacity){
		expand();
	}
	
	pos = currentCount;
	
	transcripts[pos] = new Transcript;
	transcripts[pos]->studentID = t.studentID;
	transcripts[pos]->numberOfSemesters = .numberOfSemesters;
	for (int j = 0; j < t->numberOfSemesters; ++j){
		transcripts[pos]->semesters = new Semester;
		transcripts[pos]->semesters[j].term = t.semesters[j].term;
		transcripts[pos]->semesters[j].year = t.semesters[j].year;
		transcripts[pos]->semesters[j].numberOfCourses = t.semesters[j].numberOfCourses;
		for (int k = 0; k < t[i].semesters[j].numberOfCourses; ++k){
			transcripts[pos]->semesters[j].courses = new Course;
			transcripts[pos]->semesters[j].courses[k].courseNumber = t.semesters[j].courses[k].courseNumber;
			transcripts[pos]->semesters[j].courses[k].grade = t.semesters[j].courses[k].grade;
		}
	}
	
	++currentCount
	return true;
}

Transcript* getTranscriptCopy(string studentID)
{
	
	
	
	
}




