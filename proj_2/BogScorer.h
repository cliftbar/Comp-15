//BogScorer.h

#ifndef BOGSCORER
#define BOGSCORER
#include "Dictionary.h"
#include "bog_structs.h"
//BogScorer.h
//Created by: Cameron Barclift
//Scores the results of the checker from standard input stream.
class BogScorer
{
public:
	BogScorer();	//constructor
	~BogScorer();	//destructor
	void compute_score();	//computes the score
	
private:
	//private data
	int curr_score;
	int num_words;
	int NOT_WORD_SCORE;
	
	int MAX_BIN_1;
	int BIN_1_SCORE;
	
	int MAX_BIN_2;
	int BIN_2_SCORE;
	
	int MAX_BIN_3;
	int BIN_3_SCORE;
	
	int MAX_BIN_4;
	int BIN_4_SCORE;
	
	int MIN_BIN_5;
	int BIN_5_SCORE;
};

#endif
