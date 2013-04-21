struct BogLett {
	char c;
	int row, col;
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
	