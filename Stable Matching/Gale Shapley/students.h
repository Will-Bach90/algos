#ifndef STUDENTS_H // Prevents multiple inclusions of same header file
#define STUDENTS_H
#include <iostream>
#include <queue>

class Student {
    public:
        Student();                          // default constructor
        Student(int);                       // overloaded constructor
        ~Student();                         // destructor

        std::string getName() const;        // get name of student
        int getIndex() const;               // Gets the index of student in currently considered Uni's preference list
        int getRank(int) const;             // Gets rank of Uni in student's preference list
        int getNum() const;                 // Gets index of student in studentList from GaleShapley class

        int getMatch() const;               // Gets student's current matched university

        bool setNum(int);                   // Sets index of student in studentList from GaleShapley class

        bool setIndex(int);                 // Sets index of currently considered university in preference list
        bool setRank(int);                  // Sets rank of university in student's preference list
        void printPreferenceList() const;   // Prints out student's preference list
        bool setName(std::string);

        bool setMatch(int);                 // sets student's current match

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