//---------------------------------------------------------------------------
// GALESHAPLEY.H
// ADT for implementing the Gale Shapley Algorithm.
//---------------------------------------------------------------------------
// GaleShapley class: reads data file, builds vectors of Students and Unis, and
// finds a stable matching via the Gale Shapely algo. Includes additional
// features:
//   -- Prints out list of Students and/or Unis
//   -- Prints out preference lists for Students and/or Unis
//   -- Prints out matched pairs
// Assumptions:
//   -- Student and Uni class are implemented
//   -- Data file is well formatted
//   -- Designed for Student optimality and Uni pessimality.
//---------------------------------------------------------------------------

#ifndef GALESHAPLEY_H
#define GALESHAPLEY_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include "university.h"
#include "students.h"
using namespace std;


class GaleShapley {
    public:
        GaleShapley();
        ~GaleShapley();
        bool readFile(istream&);

        void printStudentList() const;

        void printUniList() const;

        bool runGaleShapleyAlgo();

        void printMatches() const;

    private:
        // queue of pointers to unmatched students
        std::queue<Student*> q;

        std::vector<Student*> studentList;  // vector of pointers to students

        std::vector<University*> uniList;   // vector of pointers to Unis

        int size;           // number of students/Unis, size of lists.
};

#endif