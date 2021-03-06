//dictionary.h
//Created by: Cameron Barclift
//Class contains the functions neccessary for the operation of a dictionary
//using a trie data structure.  Allows for words to be stored, can print all
//words stored, and can look up whether a specific word is stored and if a
//specific string is a prefix of a word.  Dictionary contains only
//alphabetical characters; any characters that are not alphabetical are
//removed from the input string, which is then stored, even if it is empty

#include "dictionary.h"
#include "node.h"
using namespace std;

/////////////////////////////Public Methods///////////////////////////////////

//Default constructor, intialized s_curr to an empty string, root to NULL, and
//curr_s_pos to zero.
Dictionary::Dictionary()
{
	s_curr = "";
	curr_s_pos = 0;
	root = NULL;
}

//Public insert funciton, calls the word clean up fucntion and passes the
//cleaned string to the recursive insert funciton.  It also creates a new
//for root if the dictionary is empty.  Returns false if out of memory.
bool Dictionary::insert(string s)
{
	s_curr = clean_word(s);
	
	if(root == NULL){
		root = new Node;
	}
	
	return rec_insert(root);
}

//Public isPrefix function, calls the word clean up function and passes the
//cleaned string to the recursive find path function with the prefix switch 
//value set to true. Function returns true if the word is a prefix.
bool Dictionary::isPrefix(string s)
{
	s_curr = clean_word(s);
	return rec_find_path(root, true);
}

//Public isWord function, calls the word clean up function and passes the
//cleaned string to the recursive find path function with the prefix switch 
//value set to false. Function returns true if the word is in the dictionary.
bool Dictionary::isWord(string s)
{
	s_curr = clean_word(s);
	return rec_find_path(root, false);
}

//Public print all function, prints every word in the dictionary
void Dictionary::print_all_words()
{
	string print_string = "";
	rec_print(root, print_string);
}


///////////////////////////Private Methods////////////////////////////////////

//Function removes any non-alphabetical characters from the input string, and
//returns a string that contains the remaining alphabetical characters from  
//the input string.
string Dictionary::clean_word(string s_in)
{
	string r_string = "";
	
	for (unsigned int i = 0; i < s_in.length(); ++i){
		if (isalpha(s_in[i])){
			r_string += tolower(s_in[i]);
		}
	}
	
	return r_string;
}

//returns an integer from 0-25 that represents the trie array postion of the
//character passed in
int Dictionary::alpharray_pos(char c_in)
{
	return (c_in - 'a');
}

//Recursive insert function called by public insert function.  Returns false
//if there is no more memory
bool Dictionary::rec_insert(Node* np_in)
{
	int curr_elm = alpharray_pos(s_curr[curr_s_pos]);
	
	if(curr_s_pos >= s_curr.length()){
		np_in->set_word_here(true);
		curr_s_pos = 0;
		return true;
	}else{
		if(np_in->array_access(curr_elm) == NULL){
			np_in->make_node(curr_elm);
		}
		if (np_in->array_access(curr_elm) != NULL){
			++curr_s_pos;
			return rec_insert(np_in->array_access(curr_elm));
		}else {
			cerr << "ERROR: Out of memory.  Program exit" << endl;
			exit(1);
			//return false;
		}
	}
}

//Recursive function called by isPrefix and isWord.  The fucntion follows
//the path set by the current string, and checks for prefixes if the switch
//value "prefix" is true, and for whole words when "prefix" is false.  
//Returns false if the input string is not a prefix or word
bool Dictionary::rec_find_path(Node* np_in, bool prefix)
{
	int curr_elm = alpharray_pos(s_curr[curr_s_pos]);
	
	if (np_in == NULL){
		return false;
	}else if(curr_s_pos >= s_curr.length()){
		if (prefix){
			curr_s_pos =0;
			return true;
		}else {
			if (np_in->word_here()){
				curr_s_pos =0;
				return true;
			}else {
				curr_s_pos =0;
				return false;
			}
		}
	}else if(np_in->array_access(curr_elm) == NULL){
		curr_s_pos = 0;
		return false;
	}else {
		++curr_s_pos;
		return rec_find_path(np_in->array_access(curr_elm), prefix);
	}
}

//Recursive print function.  
void Dictionary::rec_print(Node* np_in, string print_string)
{
	string curr_path = print_string;
	
	if (np_in == NULL){
		cout << "Empty Dictionary" << endl;
	} else {
		if (np_in->word_here()){
			cout << print_string << endl;
		}
		
		for (int i =0; i < 26; ++i){
			print_string = curr_path;
			if (np_in->array_access(i) != NULL){
				print_string += (i + 'a');
				rec_print(np_in->array_access(i), print_string);
			}
		}
	}
}



















