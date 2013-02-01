//TOT2.cpp file for homework 1

#include "TOT2.h"

TOT2::TOT2()
{
	currentCount = 0;
	currentCapacity = INIT_SIZE;
}

TOT2::TOT2(Transcript* transcriptList, int listSize)
{	
	currentCount = 0;
	currentCapacity = INIT_SIZE;
	transcripts = new Transcript*[currentCapacity];
	
	for (int i = 0; i < listSize; ++i){
		transcripts[i] = new Transcript;
		transcripts[i]->studentID = transcriptList[i].studentID;
		transcripts[i]->numberOfSemesters = transcriptList[i].numberOfSemesters;
		transcripts[i]->semesters = new Semester[numberOfSemesters];
		for (int j = 0; j < transcripts[i]->numberOfSemesters; ++j){
			transcripts[i]->semesters[j].term = transcriptList[i].semesters[j].term;
			transcripts[i]->semesters[j].year = transcriptList[i].semesters[j].year;
			transcripts[i]->semesters[j].numberOfCourses = transcriptList[i].semesters[j].numberOfCourses;
			transcripts[i]->semesters[j].courses = new Course[numberOfCourses];
			for (int k = 0; k < transcriptList[i].semesters[j].numberOfCourses; ++k){
				transcripts[i]->semesters[j].courses[k].courseNumber = transcriptList[i].semesters[j].courses[k].courseNumber;
				transcripts[i]->semesters[j].courses[k].grade = transcriptList[i].semesters[j].courses[k].grade;
			}
		}
		
		++currentCount;
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
	transcripts[pos]->studentID = t->studentID;
	transcripts[pos]->numberOfSemesters = t->numberOfSemesters;
	for (int j = 0; j < t->numberOfSemesters; ++j){
		transcripts[pos]->semesters = new Semester;
		transcripts[pos]->semesters[j].term = t->semesters[j].term;
		transcripts[pos]->semesters[j].year = t->semesters[j].year;
		transcripts[pos]->semesters[j].numberOfCourses = t->semesters[j].numberOfCourses;
		for (int k = 0; k < t->semesters[j].numberOfCourses; ++k){
			transcripts[pos]->semesters[j].courses = new Course;
			transcripts[pos]->semesters[j].courses[k].courseNumber = t->semesters[j].courses[k].courseNumber;
			transcripts[pos]->semesters[j].courses[k].grade = t->semesters[j].courses[k].grade;
		}
	}
	
	++currentCount
	return true;
}

Transcript* getTranscriptCopy(string studentID)
{
	Transcript* hold_transcript;
	hold_transcript = NULL;
	int i = 0;
	
	do{
		if (transcripts[i]->studentID != studentID){
			++i;
		}else if (transcripts[i]->studentID == studentID){
			hold_transcript->studentID = transcripts[i]->studentID;
			hold_transcript->numberOfSemesters = transcripts[i]->numberOfSemesters;
			hold_transcript->semesters = new Semester[hold_transcript->numberOfSemesters];
			for (int j = 0; j < hold_transcript->numberOfSemesters; ++j){
				hold_transcript->semesters[j].term = transcripts[i]->semesters[j].term;
				hold_transcript->semesters[j].year = transcripts[i]->semesters[j].year;
				hold_transcript->semesters[j].numberOfCourses = transcripts[i].semesters[j].numberOfCourses;
				hold_transcript->semesters[j].courses = new Course[hold_transcript->semesters[j].numberOfCourses];
				for (int k = 0; k < hold_transcript->semesters[j].numberOfCourses; ++k){
					hold_transcript->semesters[j].courses[k].courseNumber = transcripts[i]->semesters[j].courses[k].courseNumber;
					hold_transcript->semesters[j].courses[k].grade = transcripts[i]->semesters[j].courses[k].grade;
				}
			}
			break
		}
	}
	
	//Debug couting
	cout << "hold_transcript->studentID: " << hold_transcript->studentID;
	cout << "hold_transcript->numberOfSemesters: " << hold_transcript->numberOfSemesters;
	for (int j = 0; j < hold_transcript->numberOfSemesters; ++j){
		cout << "hold_transcript->semesters[" << j << "].term: " << hold_transcript->semesters[j].term;
		cout << "hold_transcript->semesters[" << j << "].year: " << hold_transcript->semesters[j].year;
		cout << "hold_transcript->semesters[" << j << "].numberOfCourses: " << hold_transcript->semesters[j].numberOfCourses;
		cout << "hold_transcript->semesters[" << j << "].courses: " << hold_transcript->semesters[j].courses;
		for (int k = 0; k < hold_transcript->semesters[j].numberOfCourses; ++k){
			cout << "hold_transcript->semesters[" << j << "].courses[" << k << "].courseNumber:" << hold_transcript->semesters[j].courses[k].courseNumber;
			cout << "hold_transcript->semesters[" << j << "].courses[" << k << "].grade: " << hold_transcript->semesters[j].courses[k].grade;
		}
	}
	
return hold_transcript;
}




