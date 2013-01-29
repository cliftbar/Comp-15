#include "TOT.h"

TOT::TOT()

{
    currentTranscriptCount = 0;
}

TOT::TOT(Transcript* copylist, int listSize)
{
	currentTranscriptCount = listSize;
	
	for (int i = 0; i < listSize; ++i){
		Transcript* transcripts[listSize] = new Transcript;
		transcripts[i].studentID = copylist[i].studentID;
		transcripts[i].numberOfSemesters = copylist[i]->numberOfSemesters;
		transcripts[i]->semseters = new *Semester[numberOfSemesters];
		for (int j = 0; j < transcripts[i]->numberOfSemseters; ++j){
			transcripts[i].semseters[j].term = copylist[i]->semesters[j].term;
			transcripts[i].semseters[j].year = copylist[i]->semesters[j].year;
			transcripts[i].semseters[j].numberOfCourses = copylist[i]->semesters[j].numberOfCourses;
			copylist[i]->semesters[j].courses = new *course[numberOfCourses];
			for (int k = 0; k < numberOfCOurses; ++k){
				copylist[i]->semesters[j].courses = new *course[numberOfCourses];
				transcripts[i].semseters[j]->courses[k].courseNumber = copylist[i]->semesters->[j]->courses[k].courseNumber;
				transcripts[i].semseters[j]->courses[k].grade = copylist[i]->semesters->[j]->courses[k].grade;
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




