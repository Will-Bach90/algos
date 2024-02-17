#include <fstream>
#include "galeshapley.h"
using namespace std;

int main(){
    ifstream inFile("data.txt");
    GaleShapley g;
    if(g.readFile(inFile)){
        if(g.runGaleShapleyAlgo()){
            g.printMatches();
        } else{
            cout << "Matches not found." << endl;
        }
    } else{
        cout << "Invalid data. File not read." << endl;
    }
    return 0;
}
