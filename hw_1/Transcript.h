//Provided by Comp-15 Administration
//Used by Cameron Barclift
//header file included in TOT2.h

#ifndef TSCRIPT_H
#define TSCRIPT_H

#include <string>

using namespace std;

//struct definitions
//to create a transcript


struct Course
{
    string courseNumber;
    string grade;
    
};

struct Semester
{
    string term;
    int year;
    int numberOfCourses;
    Course* courses;
};


struct Transcript
{
    string studentID;
    int numberOfSemesters;
    Semester* semesters;
    
};

#endif