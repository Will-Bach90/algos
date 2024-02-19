//---------------------------------------------------------------------------
// GALESHAPLEY.CPP
// ADT for implementing the Gale Shapley Algorithm.
//---------------------------------------------------------------------------
// GaleShapley class: reads data file, builds vectors of students and universties, and
// finds a stable matching via the Gale Shapley algo. Includes additional
// features:
//   -- Prints out list of Students and/or Universities
//   -- Prints out preference lists for Students and/or Universities
//   -- Prints out matched pairs
// Assumptions:
//   -- Student and University class are implemented
//   -- Data file is well formatted
//   -- Designed for Student optimality and University pessimality.
//---------------------------------------------------------------------------

#include "galeshapley.h"

//------Default Constructor--------------------------------------------------
// Default constructor for Gale Shapley Class
// Preconditions:   None
// Postconditions:  First element in StudentList and UniList set to nullptr
// to allow for (1 -> n) based preference list, and list size initialized to 0
GaleShapley::GaleShapley(){
    studentList.push_back(nullptr);
    uniList.push_back(nullptr);
    size = 0;

}

//------Destructor-----------------------------------------------------------
// Destructor for Gale Shapley Class
// Preconditions:   StudentList and UniList filled with pointers to instances
// of the Student and Uni class, respectively.
// Postconditions:  StudentList and UniList now empty, can be handled by
// vector destructor.
GaleShapley::~GaleShapley(){
    for(int i = 0; i <= size; i++){
        delete studentList[i];
        delete uniList[i];
    }
}

//------readFile-------------------------------------------------------------
// Reads provided data file
// Preconditions:   File exists and file path is correct or exists in correct
// directory and data is well formatted - e.g. first line is size (n) of list,
// next n lines are names of student, next n lines have preference lists of
// size n, etc..
// Postconditions:  StudentList and UniList are filed with pointers to
// instances of the Student class and Uni class, queue has pointers to each
// instance of Student class, each instance now has their preference list
// vectors filled out with ints. Returns true if file is read properly.
bool GaleShapley::readFile(istream& infile){
    int pref;
    infile >> size;     // first line in file is size of list
    if (infile.eof()) return false; // break if end of file

    if(size <= 0) return false;
    string s;
    getline(infile, s);     // gets end of first line
    for(int i = 1; i <= size; i++){     // next n=size lines are Student names
        getline(infile, s);             // gets next line

        // creates pointer to new Student instance
        Student* s1 = new Student(size);
        s1->setName(s);     // sets name

        // sets number of Student in the StudentList vector for quick lookup
        s1->setNum(i);
        studentList.push_back(s1);  // adds pointer to StudentList
        q.push(s1);                 // adds pointer to queue of unmatched student
    }

    // next n=size lines are each Student's preference lists
    for(int i = 1; i <= size; i++){
        getline(infile, s);
        istringstream ss(s);

        // there are n=size preference ratings on each line
        for(int j = 1; j <= size; j++){
            ss >> pref;                     // grab preference rating (int) of jth Uni
            if(pref > 0 && pref <= size){   // if rating is valid
                studentList[i]->setRank(pref);  // set rating[j] = pref
            } else{
                return false;                   // else return false
            }
        }
        // StudentList[i]->printPrefList();
    }

    for(int i = 1; i <= size; i++){         // next n=size lines are Uni names
        getline(infile, s);
        University* u1 = new University(size);
        u1->setName(s);
        u1->setNum(i);
        uniList.push_back(u1);
    }

    // next n=size lines are each Student's preference lists
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

//------runGSAlgorithm------------------------------------------------
// Runs the Gale Shapley algorithm to find stable matching
// Preconditions:   StudentList and UniList are both of same size, queue is
// full of unmatched students.
// Postconditions:  Stable assignment, each Student is matched to one Uni,
// each Uni is matched to one Student.
bool GaleShapley::runGaleShapleyAlgo(){
    int tempIndex;
    bool indexValid;
    Student* student;
    University* uni;
    while(!q.empty()){          // while queue of unmatched students is not empty
        student = q.front();    // grab pointer to Student at front of queue
        q.pop();                // remove from queue

        // find highest ranked Uni in Student's preference list
        uni = uniList[student->getRank(student->getIndex())];
        if(!uni->isMatched()){              // if Uni is not matched
            uni->setMatch(student->getNum());   // set Uni's match to be Student
            student-> setMatch(uni->getNum());
        } else if(uni->getRank(uni->getMatch()) > uni->getRank(student->getNum())){

            // else if Uni's current match is lower rated than this new Student
            tempIndex = studentList[uni->getMatch()]->getIndex();

            // increment old match's current index to next in their preference list
            indexValid = studentList[uni->getMatch()]->setIndex(tempIndex+1);
            if(!indexValid) return false;
            studentList[uni->getMatch()]->setMatch(-1); // set old Student to be unmatched
            q.push(studentList[uni->getMatch()]);       // add old Student back to queue
            uni->setMatch(student->getNum());           // set Uni's match to be new Student
            student->setMatch(uni->getNum());           // set new Student's match to be Uni
        } else{

            // else increment Student's index to next Uni in their preference list
            indexValid = student->setIndex(student->getIndex()+1);
            if(!indexValid) return false;
            q.push(student);                // push Student back onto queue of unmatched student
        }
    }
    return true;
}

//------printMatches--------------------------------------------------------
// Prints out all matches found from the Gale Shapley algorithm
// Preconditions:   None
// Postconditions:  Prints out matches in the form (Student name / Uni name)
void GaleShapley::printMatches() const{
    for(int i = 1; i <= size; i++)
    {
        cout << studentList[i]->getName() << " / ";
        cout << uniList[studentList[i]->getMatch()]->getName() << endl;
    }
}

//------printStudentList------------------------------------------------------
// Prints out every Student in the StudentList
// Preconditions:   None
// Postconditions:  Prints out the names of each Student in the StudentList
void GaleShapley::printStudentList() const
{
    for(int i = 1; i <= size; i++)
    {
        cout << studentList.at(i)->getName() << endl;
    }
}

//------printUniList---------------------------------------------------------
// Prints out every Uni in the UniList
// Preconditions:   None
// Postconditions:  Prints out the names of each Uni in the UniList
void GaleShapley::printUniList() const
{
    for(int i = 1; i <= size; i++)
    {
        cout << uniList.at(i)->getName() << endl;
    }
}