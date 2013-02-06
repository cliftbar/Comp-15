//Created by: Cameron Barclift
//TOT2.cpp file for homework 1
//defines the functions in the class TOT2, which is declared in TOT2.h

#include "TOT2.h"

//default constuctor for the class
//It does about the minimum to not break if called
//I would really prefer if you didn't use this one, 
//since it doesn't matter for the explicit assignment
TOT2::TOT2()
{
	currentCount = 0;
	currentCapacity = INIT_SIZE;
}

//Constructor for class, intializes transcripts,
//the list of transcripts held in the class,
//from the provided list of transcripts
TOT2::TOT2(Transcript* transcriptList, int listSize)
{	
	currentCount = 0;
	currentCapacity = INIT_SIZE;
	transcripts = new Transcript*[currentCapacity];
	
	for (int i = 0; i < listSize; ++i){
		addTranscript(transcriptList);
		/*//prints every transcript added for testing purposes
		transcript_list_print(transcripts[i]);
		//*/
	}
}

//expands the dynamic array of transcripts contained in the class
//it doubles the capacity of the array
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

//The function takes a pointer to a list of transcripts
//and adds that list to transcripts (contained in the list).
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

//Function takes a student ID, finds the corrosponding transcript,
//then  returns a pointer to a COPY of the transcript
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
	
	
	/*//Debug code
	if(transcript_to_copy != NULL){
		cerr << "transcript_list_print test\n";
		transcript_list_print(hold_transcript);
	}//*/
	
return hold_transcript;
}

//The function takes a student ID, finds the corrosponding transcript, and returns a pointer to the ACTUAL transcript.
//This function is private so no one breaks the transcript list
Transcript* TOT2::lookUp(string sID)
{
	//cerr << "lookUp entered\n";
	//cerr << "sID: " << sID << endl;
	for (int i = 0; i < currentCount; ++i){
		//cerr << "transcripts[i].studentID: " << transcripts[i]->studentID << endl;
		if (transcripts[i] != NULL && transcripts[i]->studentID == sID){
			//cerr << "lookUp exited found transcript\n";
			return transcripts[i];
		}
	}

//cerr << "lookUp exited, no transcript\n";
return NULL;
}

//Takes a pointer to a transcript and prints it to the screen.
void TOT2::transcript_list_print(Transcript* t_in)
{
	cout << "t_in->studentID: " << t_in->studentID << endl;
	cout << "t_in->numberOfSemesters: " << t_in->numberOfSemesters << endl;
	for (int j = 0; j < t_in->numberOfSemesters; ++j){
		cout << "t_in->semesters[" << j << "].term: " << t_in->semesters[j].term << endl;
		cout << "t_in->semesters[" << j << "].year: " << t_in->semesters[j].year << endl;
		cout << "t_in->semesters[" << j << "].numberOfCourses: " << t_in->semesters[j].numberOfCourses << endl;
		for (int k = 0; k < t_in->semesters[j].numberOfCourses; ++k){
			cout << "t_in->semesters[" << j << "].courses[" << k << "].courseNumber:" << t_in->semesters[j].courses[k].courseNumber << endl;
			cout << "t_in->semesters[" << j << "].courses[" << k << "].grade: " << t_in->semesters[j].courses[k].grade << endl;
		}
	}
}


