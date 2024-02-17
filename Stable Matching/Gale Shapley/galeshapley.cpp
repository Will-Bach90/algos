#include "galeshapley.h"

GaleShapley::GaleShapley(){
    studentList.push_back(nullptr);
    uniList.push_back(nullptr);
    size = 0;

}

GaleShapley::~GaleShapley(){
    for(int i = 0; i <= size; i++){
        delete studentList[i];
        delete uniList[i];
    }
}

bool GaleShapley::readFile(istream& infile){
    int pref;
    infile >> size;
    if (infile.eof()) return false;

    if(size <= 0) return false;
    string s;
    getline(infile, s);
    for(int i = 1; i <= size; i++){
        getline(infile, s);

        Student* s1 = new Student(size);
        s1->setName(s);

        s1->setNum(i);
        studentList.push_back(s1);
        q.push(s1);
    }

    for(int i = 1; i <= size; i++){
        getline(infile, s);
        istringstream ss(s);

        for(int j = 1; j <= size; j++){
            ss >> pref;
            if(pref > 0 && pref <= size){
                studentList[i]->setRank(pref);
            } else{
                return false;
            }
        }
    }

    for(int i = 1; i <= size; i++){
        getline(infile, s);
        University* u1 = new University(size);
        u1->setName(s);
        u1->setNum(i);
        uniList.push_back(u1);
    }

    for(int i = 1; i <= size; i++){
        getline(infile, s);
        istringstream ss(s);

        for(int j = 1; j <= size; j++){
            ss >> pref;
            if(pref > 0 && pref <= size){
                uniList[i]->setRank(pref);
            } else{
                return false;
            }
        }
    }
    return true;

}

bool GaleShapley::runGaleShapleyAlgo(){
    int tempIndex;
    bool indexValid;
    Student* student;
    University* uni;
    while(!q.empty()){
        student = q.front();
        q.pop();

        uni = uniList[student->getRank(student->getIndex())];
        if(!uni->isMatched()){
            uni->setMatch(student->getNum());
            student-> setMatch(uni->getNum());
        } else if(uni->getRank(uni->getMatch()) > uni->getRank(student->getNum())){
            tempIndex = studentList[uni->getMatch()]->getIndex();
            indexValid = studentList[uni->getMatch()]->setIndex(tempIndex+1);
            if(!indexValid) return false;
            studentList[uni->getMatch()]->setMatch(-1);
            q.push(studentList[uni->getMatch()]);
            uni->setMatch(student->getNum());
            student->setMatch(uni->getNum());
        } else{
            indexValid = student->setIndex(student->getIndex()+1);
            if(!indexValid) return false;
            q.push(student);
        }
    }
    return true;
}

void GaleShapley::printMatches() const{
    for(int i = 1; i <= size; i++)
    {
        cout << studentList[i]->getName() << " / ";
        cout << uniList[studentList[i]->getMatch()]->getName() << endl;
    }
}

void GaleShapley::printStudentList() const
{
    for(int i = 1; i <= size; i++)
    {
        cout << studentList.at(i)->getName() << endl;
    }
}

void GaleShapley::printUniList() const
{
    for(int i = 1; i <= size; i++)
    {
        cout << uniList.at(i)->getName() << endl;
    }
}