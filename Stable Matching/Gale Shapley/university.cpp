#include "university.h"

//------Default Constructor--------------------------------------------------
// Default constructor for University Class
// Preconditions:   None
// Postconditions:  listSize initialized to 0, currentMatch to -1
University::University(){                 
    listSize = 0;
    currentMatch = -1;
}


//------Overloaded Constructor-----------------------------------------------
// Overloaded constructor for University Class
// Preconditions:   int > 0
// Postconditions:  listSize initialized to size int, currentMatch to -1,
// number to -1 (index of University in uniList from GaleShapley class),
// ndx to 1 (first value in pref list), number to -1, and prefList[0] = -1
// due to pref list being from 1 -> n   
University::University(int size){    
    listSize = size;
    currentMatch = -1;
    ndx = 1;
    number = -1;
    prefList.push_back(-1);
}

//------Destructor-----------------------------------------------------------
// Destructor for University Class
// Preconditions:   None
// Postconditions:  University instance is deleted   
University::~University(){}

//------getName--------------------------------------------------------------
// Gets name of University
// Preconditions:   None
// Postconditions:  Returns string of University's name
std::string University::getName() const { 
    return name;
}

//------getIndex-------------------------------------------------------------
// Gets index in preference list of currently considered student
// Preconditions:   None
// Postconditions:  Returns int of index 
int University::getIndex() const { 
    return ndx;
}             

//------setName--------------------------------------------------------------
// Sets Uni's name field.
// Preconditions:   None
// Postconditions:  Sets Uni's name 
bool University::setName(std::string s){
    name = s;
    return true;
}

//------getRank--------------------------------------------------------------
// Gets rank of Student in University's preference list.
// Preconditions:   0 < int <= listSize
// Postconditions:  Returns int of Student's ranking in preference list 
int University::getRank(int i) const {     
    return prefList[i];
}           

//------getNum---------------------------------------------------------------
// Gets index of University in uniList from GaleShapley class
// Preconditions:   None
// Postconditions:  Returns int of uni from uniList
int University::getNum() const {
    return number;
}


//------getMatch-------------------------------------------------------------
// Gets Uni's current match
// Preconditions:   None
// Postconditions:  Returns int of Unis current match (representing
// index of student in studentList from GaleShapley class).
int University::getMatch() const{
    return currentMatch;
}                                           


//------setNum---------------------------------------------------------------
// Sets index of Uni in uniList from GaleShapley class
// Preconditions:   0 < int <= listSize
// Postconditions:  Sets int of Uni representing index in uniList
bool University::setNum(int num){
    number = num;
    return true;
}

//------setIndex-------------------------------------------------------------
// Sets index of currently considered uni in preference list
// Preconditions:   0 < int <= listSize
// Postconditions:  sets index to int, returns true if int is valid and set
bool University::setIndex(int i){
    ndx = i;
    return true;
}


//------setRank--------------------------------------------------------------
// Sets rank of Student in Uni's preference list.
// Preconditions:   0 < int <= listSize
// Postconditions:  prefList.push_back(int) 
bool University::setRank(int i){
    this->prefList.push_back(i);
    return true;
} 

//------printPrefList--------------------------------------------------------
// Prints out Uni's preference list
// Preconditions:   None
// Postconditions:  // Prints out uni's preference list
void University::printPreferenceList() const{
    std::cout << "The preference list is as follows";
    for(int i = 1; i <= listSize; i++){
        std::cout << prefList[i] << " ";
    }
    std::cout << std::endl;
}  

//------setMatch-------------------------------------------------------------
// Sets Uni's current match
// Preconditions:   0 < int <= listSize
// Postconditions:  Sets current match to be the index of Student in
// GaleShapley class's studentList
bool University::setMatch(int m){
    currentMatch = m;
    return true;
}                 // sets university's current match

//------isMatched-------------------------------------------------------------
// Checks to see if uni is currently matech
// Preconditions:   uni has private data member representing their current 
// match.
// Postconditions:  returns true if currently matched, false otherwise
bool University::isMatched() const
{
    return (currentMatch != -1);
}