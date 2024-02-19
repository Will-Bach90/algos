//---------------------------------------------------------------------------
// UNIVERSITY.H
// ADT for storing University.
//---------------------------------------------------------------------------
// Student class: used for storing information about University, including their
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
#ifndef UNIVERSITY_H // Prevents multiple inclusions of same header file
#define UNIVERSITY_H
#include <iostream>
#include <queue>

class University {
    public:

        //------Default Constructor--------------------------------------------------
        // Default constructor for University Class
        // Preconditions:   None
        // Postconditions:  listSize initialized to 0, currentMatch to -1
        University();       

        //------Overloaded Constructor-----------------------------------------------
        // Overloaded constructor for University Class
        // Preconditions:   int > 0
        // Postconditions:  listSize initialized to size int, currentMatch to -1,
        // number to -1 (index of University in uniList from GaleShapley class),
        // ndx to 1 (first value in pref list), number to -1, and prefList[0] = -1
        // due to pref list being from 1 -> n                       
        University(int);        

        //------Destructor-----------------------------------------------------------
        // Destructor for University Class
        // Preconditions:   None
        // Postconditions:  University instance is deleted                  
        ~University();                         

        //------getName--------------------------------------------------------------
        // Gets name of University
        // Preconditions:   None
        // Postconditions:  Returns string of University's name
        std::string getName() const;        

        //------getIndex-------------------------------------------------------------
        // Gets index in preference list of currently considered student
        // Preconditions:   None
        // Postconditions:  Returns int of index        
        int getIndex() const;

        //------getRank--------------------------------------------------------------
        // Gets rank of Student in University's preference list.
        // Preconditions:   0 < int <= listSize
        // Postconditions:  Returns int of Student's ranking in preference list        
        int getRank(int) const;

        //------getNum---------------------------------------------------------------
        // Gets index of University in uniList from GaleShapley class
        // Preconditions:   None
        // Postconditions:  Returns int of uni from uniList
        int getNum() const; 
        
        //------getMatch-------------------------------------------------------------
        // Gets Uni's current match
        // Preconditions:   None
        // Postconditions:  Returns int of Unis current match (representing
        // index of student in studentList from GaleShapley class).
        int getMatch() const;        

        //------setNum---------------------------------------------------------------
        // Sets index of Uni in uniList from GaleShapley class
        // Preconditions:   0 < int <= listSize
        // Postconditions:  Sets int of Uni representing index in uniList
        bool setNum(int); 

        //------setIndex-------------------------------------------------------------
        // Sets index of currently considered uni in preference list
        // Preconditions:   0 < int <= listSize
        // Postconditions:  sets index to int, returns true if int is valid and set
        bool setIndex(int);

        //------setRank--------------------------------------------------------------
        // Sets rank of Student in Uni's preference list.
        // Preconditions:   0 < int <= listSize
        // Postconditions:  prefList.push_back(int)  
        bool setRank(int);                  

        //------printPrefList--------------------------------------------------------
        // Prints out Uni's preference list
        // Preconditions:   None
        // Postconditions:  // Prints out uni's preference list
        void printPreferenceList() const; 

        //------setMatch-------------------------------------------------------------
        // Sets Uni's current match
        // Preconditions:   0 < int <= listSize
        // Postconditions:  Sets current match to be the index of Student in
        // GaleShapley class's studentList
        bool setMatch(int);       

        //------setName--------------------------------------------------------------
        // Sets Uni's name field.
        // Preconditions:   None
        // Postconditions:  Sets Uni's name                  
        bool setName(std::string);

        //------isMatched-------------------------------------------------------------
        // Checks to see if uni is currently matech
        // Preconditions:   uni has private data member representing their current 
        // match.
        // Postconditions:  returns true if currently matched, false otherwise
        bool isMatched() const;

    private:
        std::string name;               // university's name
        int ndx;                        // index of preference list currently being considered
        int currentMatch;               // University's current match
        int listSize;                   // size of preference list
        std::vector<int> prefList;      // preference list
        int number;                     // index of person in GaleShapley's university list
};


#endif