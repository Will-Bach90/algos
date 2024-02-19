#include <fstream>
#include "galeshapley.h"
using namespace std;

int main(){
    ifstream inFile("data.txt");    // get data file
    GaleShapley g;                  // create instance of GaleShapley class
    if(g.readFile(inFile)){         // if file can be read
        if(g.runGaleShapleyAlgo()){ // if galeshapley algorithm can be run successfully
            g.printMatches();       // print out stable matching
        } else{
            cout << "Matches not found." << endl;   // else error message
        }
    } else{
        cout << "Invalid data. File not read." << endl; // else error message
    }
    return 0;
}