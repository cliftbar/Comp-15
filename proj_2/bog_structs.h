//bog_structs.h
//Created by: Cameron Barclift
//Contains all the structs used by the various boggle functions
struct BogLett {
	char c;
	int row, col;
};

struct Letter
{
	BogLett l;
	bool visited;
};

struct BogWord {
	int numLetts;
	BogLett* letts;
};

struct BogWordList {
	int numWords;
	BogWord* words;
};

struct BogLettList
{
	BogLett letter;
	BogLettList* next;
};

struct Linked_Words
{
	BogWord word;
	string str_word;
	Linked_Words* next;
};
