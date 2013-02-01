//TOT2.cpp file for homework 1

TOT2::TOT2()

{
	currentCount = 0;
	currentCapacity = INIT_SIZE;
}

TOT2::TOT2(Transcript* transcriptList, int listSize)
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

void TOT2::expand()
{
	Transcript** temp = new Transcript*[currentCount * RESIZE_FACTOR];
	
	for (int i = 0; i < currentCount; ++i){
		temp[i] = transcripts[i];
	}
	
	delete transcripts;
	
	transcripts = temp;
	temp = NULL;
}