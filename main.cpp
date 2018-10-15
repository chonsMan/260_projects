
//**********************************************************************//
//   File: main.cpp
//Purpose: Opens a file and reads from it. Executes user I/O. Writes
//         changes back to the file. 
//**********************************************************************//
#include "label.hpp"
#include <fstream>
#include <string>
#include "interface.hpp"

using namespace std;

int main(){
    ifstream stream{"test.txt"}; //open file

    Label label; //make a label
    stream >> label;//read in label
    stream.close(); //close file so it can be written to
     
    while (interface_execute(cin, cout, label)); //execute user i/o
    
    ofstream output{"test.txt"}; //write changes to file
    output << label << endl; //output the label
}

