#include "TOT.h"

TOT::TOT()

{
    currentTranscriptCount = 0;
}

TOT::TOT(Transcript* transcriptList, int listSize)
{
	currentTranscriptCount = listSize;
	
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



Transcript* TOT::lookUp(string sID)
{
    int i = 0;
    while (i < MAX_SIZE && (transcripts[i]->studentID != sID ))
    {
        i++;
    }
        
    if (i < MAX_SIZE)
    {
        return transcripts[i];
    }
    
    else
    {
        return NULL;
    }
}




