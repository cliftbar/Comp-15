//TOT2.cpp file for homework 1

#include "TOT2.h"

TOT2::TOT2()
{
	currentCount = 0;
	currentCapacity = INIT_SIZE;
}

TOT2::TOT2(Transcript* transcriptList, int listSize)
{	
	cerr << "TOT2(Transcript* transcriptList, int listSize) take 2 entered.\n";
	currentCount = 0;
	currentCapacity = INIT_SIZE;
	transcripts = new Transcript*[currentCapacity];
	
	for (int i = 0; i < listSize; ++i){
		addTranscript(transcriptList);
	}
	cerr << "TOT2(Transcript* transcriptList, int listSize) take 2 left.\n";
}

void TOT2::expand()
{
	Transcript** temp = NULL;
	currentCapacity = currentCount*RESIZE_FACTOR;
	temp = new Transcript*[currentCapacity];
	
	for (int i = 0; i < currentCount; ++i){
		temp[i] = transcripts[i];
	}
	
	delete transcripts;
	
	transcripts = temp;
	temp = NULL;
}

bool TOT2::addTranscript(Transcript* t)
{
	//cerr << "TOT2::addTranscript(Transcript* t) entered.\n";//debug code
	if (currentCount >= currentCapacity){
		//cerr << "addTranscript tried to expanded array.\n";//debug code
		expand();
	}else{
		//cerr << "addTranscript did not expand array.\n";//debug code
	}
	
	
	transcripts[currentCount] = new Transcript;
	//cerr << "check_1\n";//debug code
	transcripts[currentCount]->studentID = t[currentCount].studentID;
	//cerr << "check_2: t[currentCount].studentID: " << t[currentCount].studentID << endl;//debug code
	//cerr << t[currentCount].studentID << endl;//debug code
	transcripts[currentCount]->numberOfSemesters = t[currentCount].numberOfSemesters;
	transcripts[currentCount]->semesters = new Semester[t[currentCount].numberOfSemesters];
	for (int j = 0; j < t[currentCount].numberOfSemesters; ++j){
		//cerr << "check_4\n";//debug code
		//cerr << "currentCount: " << currentCount << endl;//debug code
		transcripts[currentCount]->semesters[j].term = t[currentCount].semesters[j].term;
		transcripts[currentCount]->semesters[j].year = t[currentCount].semesters[j].year;
		transcripts[currentCount]->semesters[j].numberOfCourses = t[currentCount].semesters[j].numberOfCourses;
		transcripts[currentCount]->semesters[j].courses = new Course[t[currentCount].semesters[j].numberOfCourses];
		for (int k = 0; k < t[currentCount].semesters[j].numberOfCourses; ++k){
			//cerr << "check_5\n";//debug code
			//cerr << t[currentCount].semesters[j].courses[k].courseNumber << endl;//deug code
			transcripts[currentCount]->semesters[j].courses[k].courseNumber = t[currentCount].semesters[j].courses[k].courseNumber;
			//cerr << t[currentCount].semesters[j].courses[k].grade << endl;//debug code
			transcripts[currentCount]->semesters[j].courses[k].grade = t[currentCount].semesters[j].courses[k].grade;
		}
		//cerr << "check_3\n";//debug code
	}
	
	++currentCount;
	//cerr << "TOT2::addTranscript(Transcript* t) left.\n";//debug code
	return true;
}

/*
Transcript* TOT2::getTranscriptCopy(string studentID)
{
	//cerr << "TOT2::getTranscriptCopy(string studentID) entered\n";
	Transcript* hold_transcript;
	hold_transcript = NULL;
	
	for (int i = 0; i < currentCount; ++i){
		if (transcripts[i]!= NULL && transcripts[i]->studentID != studentID){
			//cerr << "transcripts[i]->studentID: " << transcripts[i]->studentID << endl;//debug code
			//cerr << "studentID: " << studentID << endl;//debug code
			//cerr << i << endl;//debug code
			//cerr << "^^not the same, ++i.\n";//debug code
			
		}else if (transcripts[i] != NULL && transcripts[i]->studentID == studentID){
			//cerr << "studentID found.\n";//debug code
			hold_transcript = new Transcript;
			hold_transcript->studentID = transcripts[i]->studentID;
			hold_transcript->numberOfSemesters = transcripts[i]->numberOfSemesters;
			hold_transcript->semesters = new Semester[transcripts[i]->numberOfSemesters];
			for (int j = 0; j < transcripts[i]->numberOfSemesters; ++j){
				//cerr << "check_6\n";//debug code
				hold_transcript->semesters[j].term = transcripts[i]->semesters[j].term;
				hold_transcript->semesters[j].year = transcripts[i]->semesters[j].year;
				hold_transcript->semesters[j].numberOfCourses = transcripts[i]->semesters[j].numberOfCourses;
				hold_transcript->semesters[j].courses = new Course[transcripts[i]->semesters[j].numberOfCourses];
				for (int k = 0; k < transcripts[i]->semesters[j].numberOfCourses; ++k){
					//cerr << "check_7\n";//debug code
					//cerr << "courseNumber added: " << transcripts[i]->semesters[j].courses[k].courseNumber << endl;//debug code
					//cerr << "grade added: " << transcripts[i]->semesters[j].courses[k].courseNumber << endl;//debug code
					hold_transcript->semesters[j].courses[k].courseNumber = transcripts[i]->semesters[j].courses[k].courseNumber;
					hold_transcript->semesters[j].courses[k].grade = transcripts[i]->semesters[j].courses[k].grade;
				}
			}
		//cerr << "breaking loop\n";//debug code
		break;
		}
		//cerr << "check_8\n";//debug code
	}
	
	
	//Debug code
	cerr << "hold_transcript->studentID: " << hold_transcript->studentID << endl;
	cerr << "hold_transcript->numberOfSemesters: " << hold_transcript->numberOfSemesters << endl;
	for (int j = 0; j < hold_transcript->numberOfSemesters; ++j){
		cerr << "hold_transcript->semesters[" << j << "].term: " << hold_transcript->semesters[j].term << endl;
		cerr << "hold_transcript->semesters[" << j << "].year: " << hold_transcript->semesters[j].year << endl;
		cerr << "hold_transcript->semesters[" << j << "].numberOfCourses: " << hold_transcript->semesters[j].numberOfCourses << endl;
		cerr << "hold_transcript->semesters[" << j << "].courses: " << hold_transcript->semesters[j].courses << endl;
		for (int k = 0; k < hold_transcript->semesters[j].numberOfCourses; ++k){
			cerr << "hold_transcript->semesters[" << j << "].courses[" << k << "].courseNumber:" << hold_transcript->semesters[j].courses[k].courseNumber << endl;
			cerr << "hold_transcript->semesters[" << j << "].courses[" << k << "].grade: " << hold_transcript->semesters[j].courses[k].grade << endl;
		}
	}
	//
return hold_transcript;
}
*/

//take 2
Transcript* TOT2::getTranscriptCopy(string studentID)
{
	//cerr << "TOT2::getTranscriptCopy(string studentID) entered\n";
	Transcript* hold_transcript;
	Transcript* transcript_to_copy;
	hold_transcript = NULL;
	transcript_to_copy = lookUp(studentID);
	
	if (transcript_to_copy != NULL){
		//cerr << "studentID found.\n";//debug code
		hold_transcript = new Transcript;
		hold_transcript->studentID = transcript_to_copy->studentID;
		hold_transcript->numberOfSemesters = transcript_to_copy->numberOfSemesters;
		hold_transcript->semesters = new Semester[transcript_to_copy->numberOfSemesters];
		for (int j = 0; j < transcript_to_copy->numberOfSemesters; ++j){
			//cerr << "check_6\n";//debug code
			hold_transcript->semesters[j].term = transcript_to_copy->semesters[j].term;
			hold_transcript->semesters[j].year = transcript_to_copy->semesters[j].year;
			hold_transcript->semesters[j].numberOfCourses = transcript_to_copy->semesters[j].numberOfCourses;
			hold_transcript->semesters[j].courses = new Course[transcript_to_copy->semesters[j].numberOfCourses];
			for (int k = 0; k < transcript_to_copy->semesters[j].numberOfCourses; ++k){
				//cerr << "check_7\n";//debug code
				//cerr << "courseNumber added: " << transcript_to_copy->semesters[j].courses[k].courseNumber << endl;//debug code
				//cerr << "grade added: " << transcript_to_copy->semesters[j].courses[k].courseNumber << endl;//debug code
				hold_transcript->semesters[j].courses[k].courseNumber = transcript_to_copy->semesters[j].courses[k].courseNumber;
				hold_transcript->semesters[j].courses[k].grade = transcript_to_copy->semesters[j].courses[k].grade;
			}
		}
	}
	
	//Debug code
	cerr << "hold_transcript->studentID: " << hold_transcript->studentID << endl;
	cerr << "hold_transcript->numberOfSemesters: " << hold_transcript->numberOfSemesters << endl;
	for (int j = 0; j < hold_transcript->numberOfSemesters; ++j){
		cerr << "hold_transcript->semesters[" << j << "].term: " << hold_transcript->semesters[j].term << endl;
		cerr << "hold_transcript->semesters[" << j << "].year: " << hold_transcript->semesters[j].year << endl;
		cerr << "hold_transcript->semesters[" << j << "].numberOfCourses: " << hold_transcript->semesters[j].numberOfCourses << endl;
		cerr << "hold_transcript->semesters[" << j << "].courses: " << hold_transcript->semesters[j].courses << endl;
		for (int k = 0; k < hold_transcript->semesters[j].numberOfCourses; ++k){
			cerr << "hold_transcript->semesters[" << j << "].courses[" << k << "].courseNumber:" << hold_transcript->semesters[j].courses[k].courseNumber << endl;
			cerr << "hold_transcript->semesters[" << j << "].courses[" << k << "].grade: " << hold_transcript->semesters[j].courses[k].grade << endl;
		}
	}
	//*/
return hold_transcript;
}

Transcript* lookUp(string sID)
{
	for (int i = 0; i < currentCount; ++i){
		if (transcripts[i] != NULL && transcripts[i]->studentID == studentID){
			return transcripts;
		}else{
			return NULL;
		} 
return NULL;
}



