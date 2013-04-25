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
	string word;
	Linked_Words* next;
};
