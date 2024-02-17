#ifndef UNIVERSITY_H // Prevents multiple inclusions of same header file
#define UNIVERSITY_H
#include <iostream>
#include <queue>

class University {
    public:
        University();                          // default constructor
        University(int);                       // overloaded constructor
        ~University();                         // destructor

        std::string getName() const;        // get name of university
        int getIndex() const;               // Gets the index of university in currently considered Uni's preference list
        int getRank(int) const;             // Gets rank of Uni in university's preference list
        int getNum() const;                 // Gets index of university in studentList from GaleShapley class

        int getMatch() const;               // Gets university's current matched university

        bool setNum(int);                   // Sets index of university in studentList from GaleShapley class

        bool setIndex(int);                 // Sets index of currently considered university in preference list
        bool setRank(int);                  // Sets rank of university in university's preference list
        void printPreferenceList() const;   // Prints out university's preference list

        bool setMatch(int);                 // sets university's current match
        bool setName(std::string);

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