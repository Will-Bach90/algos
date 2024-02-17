#include "students.h"

Student::Student(){                 // default constructor
    listSize = 0;
    currentMatch = -1;
}

Student::Student(int size){         // overloaded constructor
    listSize = size;
    currentMatch = -1;
    ndx = 1;
    number = -1;
    prefList.push_back(-1);
}

Student::~Student(){                            // destructor

}

std::string Student::getName() const {        // get name of student
    return name;
}

int Student::getIndex() const {             // Gets the index of student in currently considered Uni's preference list
    return ndx;
}             


int Student::getRank(int i) const {          // Gets rank of Uni in student's preference list
    return prefList[i];
}           


int Student::getNum() const {
    return number;
}                                           // Gets index of student in studentList from GaleShapley class


int Student::getMatch() const{
    return currentMatch;
}                                           // Gets student's current matched university


bool Student::setNum(int num){
    number = num;
    return true;
}                                           // Sets index of student in studentList from GaleShapley class


bool Student::setIndex(int i){
    ndx = i;
    return true;
}                                           // Sets index of currently considered university in preference list


bool Student::setRank(int i){
    this->prefList.push_back(i);
    return true;
}                                           // Sets rank of university in student's preference list


void Student::printPreferenceList() const{
    std::cout << "The preference list is as follows";
    for(int i = 1; i <= listSize; i++){
        std::cout << prefList[i] << " ";
    }
    std::cout << std::endl;
}   // Prints out student's preference list


bool Student::setMatch(int m){
    currentMatch = m;
    return true;
}                 // sets student's current match

bool Student::setName(std::string s){
    name = s;
    return true;
}

bool Student::isMatched() const
{
    return (currentMatch != -1);
}