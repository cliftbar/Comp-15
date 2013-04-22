#include <iostream>
#include <stack>
#include <vector>
#include <cstdlib>


using namespace std;


struct TLink {
		string mkey;
		int label;
		int first;
		int second;
};

void search(TLink m[])
{

	//Your code here
    //You will use the stack stl to perform a depth first
    //search. The vector will store the traversal.
    //Print the node i.e. label from the vector.
    
    stack<int> s1;
    vector<int> v1;
    
    s1.push(m[0].label);
    TLink temp = m[0];
    
    while(!s1.empty() && temp.mkey != "LINKY"){
	    temp = m[s1.top()];
	    s1.pop();
	    if (temp.second != 0){
		    s1.push(temp.second);
	    }
	    if (temp.first != 0){
		    s1.push(temp.first);
	    }
	    
	    if (temp.mkey != "LINKY"){
		    v1.push_back(temp.label);
		}
    }
    
    for (int i = 0; i < v1.size(); ++i){
	    cout << v1[i] << " ";
    }
    cout << endl;
    
}


int main() {
	
	TLink monkA[63] = { {"Why", 0, 1, 2 }, {"does", 1, 3, 4},	  {"this", 2, 5,6},	  {"monkey", 3, 7, 8}, 
					    {"keep", 4, 9, 10},	 {"getting", 5, 11, 12}, {"lost?", 6, 13, 14},  {"Is", 7, 15,16},
						{"it" , 8, 17, 18}, {"running", 9, 19, 20}, {"away?", 10, 21, 22},  {"I", 11, 23, 24},
						{"I", 12, 25, 26 },  {"think", 13, 27, 28},	  {"these", 14, 29, 30},   {"kidnappings",15,  31, 32}, 
					    {"have",16, 33, 34}, {"been", 17, 35, 36},    {"staged", 18, 37, 38}, {"I", 19, 39,40},
						{"don't", 20, 41,42}, {"care",21, 43, 44},    {"if",22, 45, 46},	  {"I", 23,47, 48},
						{"ever",24, 49, 50},  {"see", 25,51, 52},	  {"that", 26,53, 54},   {"creature",27, 55, 56}, 
					    {"again!",29, 57, 58}, {"Do", 30, 59, 60},    {"you", 31, 61, 62}, {"think" ,32,0,0},
						{"this",33,0,0},	{"will",34, 0, 0},    {"be", 35, 0, 0},	  {"on",36, 0, 0},
						{"the" ,37, 0, 0}, {"midterm?",38, 0,0}, {"I",39,  0, 0},  {"bet",40, 0, 0},
						{"somehow",41, 0, 0 },  {"this",42, 0,0},	  {"relates", 43, 0, 0},   {"to",44, 0, 0}, 
					    {"trees,",45, 0, 0}, {"Wait", 46, 0, 0},    {"LINKY", 47, 0, 0}, {"is",48, 0,0},
						{"a",49, 0,0}, {"monkey",50, 0,0},    {"maybe", 51, 0, 0},	  {"he", 52, 0, 0},
						{"is", 53, 0, 0},  {"in",54, 0, 0},	  {"a",55, 0, 0},   {"tree?", 56, 0, 0}, 
					    {"That's",57, 0, 0}, {"it", 58, 0, 0},    {"I",59, 0, 0}, {"need",60, 0,0},
						{"to",61, 0,0}, {"search", 62, 0, 0},    {"trees", 63, 0, 0}};	  	
	
	
	search(monkA);
    
    cout <<"Using a depth first search the order of nodes visited to find linky is: " << endl;
    
    cout << " 0 1 3 7 15 32 33 16 34 35 8 17 36 37 18 38 39 4 9 19 40 41 20 42 43 10 21 44 45 22 46 " << endl;

	return 0;
}
