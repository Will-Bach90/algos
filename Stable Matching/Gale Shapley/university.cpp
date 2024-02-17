#include "university.h"

University::University(){                 // default constructor
    listSize = 0;
    currentMatch = -1;
}

University::University(int size){         // overloaded constructor
    listSize = size;
    currentMatch = -1;
    ndx = 1;
    number = -1;
    prefList.push_back(-1);
}

University::~University(){                            // destructor

}

std::string University::getName() const {        // get name of university
    return name;
}

int University::getIndex() const {             // Gets the index of university in currently considered Uni's preference list
    return ndx;
}             

bool University::setName(std::string s){
    name = s;
    return true;
}


int University::getRank(int i) const {          // Gets rank of Uni in university's preference list
    return prefList[i];
}           


int University::getNum() const {
    return number;
}                                           // Gets index of university in studentList from GaleShapley class


int University::getMatch() const{
    return currentMatch;
}                                           // Gets university's current matched university


bool University::setNum(int num){
    number = num;
    return true;
}                                           // Sets index of university in studentList from GaleShapley class


bool University::setIndex(int i){
    ndx = i;
    return true;
}                                           // Sets index of currently considered university in preference list


bool University::setRank(int i){
    this->prefList.push_back(i);
    return true;
}                                           // Sets rank of university in university's preference list


void University::printPreferenceList() const{
    std::cout << "The preference list is as follows";
    for(int i = 1; i <= listSize; i++){
        std::cout << prefList[i] << " ";
    }
    std::cout << std::endl;
}   // Prints out university's preference list


bool University::setMatch(int m){
    currentMatch = m;
    return true;
}                 // sets university's current match

bool University::isMatched() const
{
    return (currentMatch != -1);
}