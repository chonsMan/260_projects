//**********************************************************************//
//   Name: Jesse Harris
//  Class: CS-260-0-44100
//Project: Project 1 - Cs_260_Record_Label
//   File: main.cpp
//Purpose: Opens a file and reads from it. Executes user I/O. Writes
//         changes back to the file. The purpose of the entire program is
//		   to offer a user a way to interact with and generate a record 
//		   label. Within the label, there is an artist object. Each
//		   artist has a name, description, and top story. It will further
//         list all songs from that artist in order of populatiry. Also
//		   included in the list of songs will be their length, views,
//         likes, and song name. The program can also read in data from 
//         a file and write that data out to the same file for an update. 
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

