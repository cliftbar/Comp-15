#ifndef TESTDAT_H
#define TESTDAT_H

/*
 * TestDat.h
 *  version 2013-01-30
 */

#include "Transcript.h"
using namespace std;

/*
 * this header file declares the data stored in the file called TestDat.cpp
 *
 * TestDat.cpp contains an array of transcripts with many elements.
 *
 * The array is called tsList.  The number of elements is called tsNum.
 *
 * It is a global variable, which, we know, is not a good idea, but
 * at this point in the course, offers the simplest way for you to
 * get access to a lot of data to feed into your class.
 *
 * All you need to do is 
 *
 *   [a] #include "TestDat.h"    in your main.cpp file
 *   [b] Write code that uses these variables
 *   [c] compile with g++ ... main.cpp ... TestDat.cpp 
 *
 * where ... indicates where you put the usual options and the names
 * of the other source files.
 */

extern Transcript	tsList[];	// the array of Transcript structs
extern int		tsNum;		// number of elements in the array

/*
 * the magic word 'extern' tells the compiler that the variables tsList[]
 * and tsNum are defined externally from main.
 */

#endif
