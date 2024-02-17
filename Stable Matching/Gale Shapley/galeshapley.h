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
        std::queue<Student*> q;

        std::vector<Student*> studentList;

        std::vector<University*> uniList;

        int size;
};

#endif