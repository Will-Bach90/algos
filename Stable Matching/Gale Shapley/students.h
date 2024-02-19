//---------------------------------------------------------------------------
// STUDENTS.H
// ADT for storing Students.
//---------------------------------------------------------------------------
// Student class: used for storing information about Students, including their
// names and preference lists. Includes additional features:
//   -- Has the ability to check if Student is matched
//   -- Stores index of match if Student is matched, -1 otherwise
//   -- Has the ability to print out Student's preference list
// Assumptions:
//   -- Size of preference list defaults to 0 if not specified
//   -- currentMatch initialized to -1
//   -- if listSize specified, preference list vector initialized to size
//      listSize filled with 0s.
//---------------------------------------------------------------------------
#ifndef STUDENTS_H // Prevents multiple inclusions of same header file
#define STUDENTS_H
#include <iostream>
#include <queue>

class Student {
    public:

        //------Default Constructor--------------------------------------------------
        // Default constructor for Student Class
        // Preconditions:   None
        // Postconditions:  listSize initialized to 0, currentMatch to -1
        Student(); 

        //------Overloaded Constructor-----------------------------------------------
        // Overloaded constructor for Student Class
        // Preconditions:   int > 0
        // Postconditions:  listSize initialized to size int, currentMatch to -1,
        // number to -1 (index of Student in studentList from GaleShapley class),
        // ndx to 1 (first value in pref list), number to -1, and prefList[0] = -1
        // due to pref list being from 1 -> n                      
        Student(int);   

        //------Destructor-----------------------------------------------------------
        // Destructor for Student Class
        // Preconditions:   None
        // Postconditions:  Student instance is deleted            
        ~Student();                         

        //------getName--------------------------------------------------------------
        // Gets name of Student
        // Preconditions:   None
        // Postconditions:  Returns string of Student's name
        std::string getName() const;        

        //------getIndex-------------------------------------------------------------
        // Gets index in preference list of currently considered university
        // Preconditions:   None
        // Postconditions:  Returns int of index
        int getIndex() const;               

        //------getRank--------------------------------------------------------------
        // Gets rank of University in Student's preference list.
        // Preconditions:   0 < int <= listSize
        // Postconditions:  Returns int of University's ranking in preference list
        int getRank(int) const;             

        //------getNum---------------------------------------------------------------
        // Gets index of Student in studentList from GaleShapley class
        // Preconditions:   None
        // Postconditions:  Returns int of student from studentList
        int getNum() const;                 

        //------getMatch-------------------------------------------------------------
        // Gets Student's current match
        // Preconditions:   None
        // Postconditions:  Returns int of Student's current match (representing
        // index of Uni in UniList from GaleShapley class).
        int getMatch() const;               

        //------setNum---------------------------------------------------------------
        // Sets index of Student in studentList from GaleShapley class
        // Preconditions:   0 < int <= listSize
        // Postconditions:  Sets int of Student representing index in studentList
        bool setNum(int);                   

        //------setIndex-------------------------------------------------------------
        // Sets index of currently considered uni in preference list
        // Preconditions:   0 < int <= listSize
        // Postconditions:  sets index to int, returns true if int is valid and set
        bool setIndex(int);              

        //------setRank--------------------------------------------------------------
        // Sets rank of Uni in Student's preference list.
        // Preconditions:   0 < int <= listSize
        // Postconditions:  prefList.push_back(int)   
        bool setRank(int);                  

        //------printPrefList--------------------------------------------------------
        // Prints out Student's preference list
        // Preconditions:   None
        // Postconditions:  // Prints out student's preference list
        void printPreferenceList() const;   

        //------setName--------------------------------------------------------------
        // Sets students name field.
        // Preconditions:   None
        // Postconditions:  Sets Student's name
        bool setName(std::string);


        //------setMatch-------------------------------------------------------------
        // Sets Student's current match
        // Preconditions:   0 < int <= listSize
        // Postconditions:  Sets current match to be the index of Uni in
        // GaleShapley class's uniList
        bool setMatch(int);                 

        //------isMatched-------------------------------------------------------------
        // Checks to see if student is currently matech
        // Preconditions:   student has private data member representing their current 
        // match.
        // Postconditions:  returns true if currently matched, false otherwise
        bool isMatched() const;

    private:
        std::string name;               //student's name
        int ndx;                        // index of preference list currently being considered
        int currentMatch;               // Student's current match
        int listSize;                   // size of preference list
        std::vector<int> prefList;      // preference list
        int number;                     // index of person in GaleShapley's student list
};


#endif