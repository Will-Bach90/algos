#include "students.h"


//------Default Constructor--------------------------------------------------
// Default constructor for Student Class
// Preconditions:   None
// Postconditions:  listSize initialized to 0, currentMatch to -1
Student::Student(){                 
    listSize = 0;
    currentMatch = -1;
}

//------Overloaded Constructor-----------------------------------------------
// Overloaded constructor for Student Class
// Preconditions:   int > 0
// Postconditions:  listSize initialized to size int, currentMatch to -1,
// number to -1 (index of Student in studentList from GaleShapley class),
// ndx to 1 (first value in pref list), number to -1, and prefList[0] = -1
// due to pref list being from 1 -> n     
Student::Student(int size){         
    listSize = size;
    currentMatch = -1;
    ndx = 1;
    number = -1;
    prefList.push_back(-1);
}

//------Destructor-----------------------------------------------------------
// Destructor for Person Class
// Preconditions:   None
// Postconditions:  Student instance is deleted   
Student::~Student(){}

//------getName--------------------------------------------------------------
// Gets name of Student
// Preconditions:   None
// Postconditions:  Returns string of Student's name
std::string Student::getName() const {        
    return name;
}

//------getIndex-------------------------------------------------------------
// Gets index in preference list of currently considered university
// Preconditions:   None
// Postconditions:  Returns int of index
int Student::getIndex() const { 
    return ndx;
}             

//------getRank--------------------------------------------------------------
// Gets rank of University in Student's preference list.
// Preconditions:   0 < int <= listSize
// Postconditions:  Returns int of Student's ranking in preference list
int Student::getRank(int i) const {      
    return prefList[i];
}           

//------getNum---------------------------------------------------------------
// Gets index of Student in studentList from GaleShapley class
// Preconditions:   None
// Postconditions:  Returns int of student from studentList
int Student::getNum() const {
    return number;
}                                           

//------getMatch-------------------------------------------------------------
// Gets Student's current match
// Preconditions:   None
// Postconditions:  Returns int of Student's current match (representing
// index of Uni in UniList from GaleShapley class).
int Student::getMatch() const{
    return currentMatch;
}

//------setNum---------------------------------------------------------------
// Sets index of Student in studentList from GaleShapley class
// Preconditions:   0 < int <= listSize
// Postconditions:  Sets int of Student representing index in studentList
bool Student::setNum(int num){
    number = num;
    return true;
}                                          

//------setIndex-------------------------------------------------------------
// Sets index of currently considered uni in preference list
// Preconditions:   0 < int <= listSize
// Postconditions:  sets index to int, returns true if int is valid and set
bool Student::setIndex(int i){
    ndx = i;
    return true;
}                                       

//------setRank--------------------------------------------------------------
// Sets rank of Uni in Student's preference list.
// Preconditions:   0 < int <= listSize
// Postconditions:  prefList.push_back(int)   
bool Student::setRank(int i){
    this->prefList.push_back(i);
    return true;
}                                        

//------printPrefList--------------------------------------------------------
// Prints out Student's preference list
// Preconditions:   None
// Postconditions:  // Prints out student's preference list
void Student::printPreferenceList() const{
    std::cout << "The preference list is as follows";
    for(int i = 1; i <= listSize; i++){
        std::cout << prefList[i] << " ";
    }
    std::cout << std::endl;
}   // Prints out student's preference list


//------setMatch-------------------------------------------------------------
// Sets Student's current match
// Preconditions:   0 < int <= listSize
// Postconditions:  Sets current match to be the index of Uni in
// GaleShapley class's uniList
bool Student::setMatch(int m){
    currentMatch = m;
    return true;
}                 // sets student's current match

//------setName--------------------------------------------------------------
// Gets rank of Uni in Student's preference list.
// Preconditions:   None
// Postconditions:  Sets Student's name
bool Student::setName(std::string s){
    name = s;
    return true;
}

//------isMatched-------------------------------------------------------------
// Checks to see if student is currently matech
// Preconditions:   student has private data member representing their current 
// match.
// Postconditions:  returns true if currently matched, false otherwise
bool Student::isMatched() const
{
    return (currentMatch != -1);
}