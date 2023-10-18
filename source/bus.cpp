#include <iostream>
#include <string>
#include <fstream> 

#include "bus.hpp"
#include "parse.hpp"

using namespace std;

Bus::Bus(string busPath){
    // Open the file
    ifstream busFile;
    busFile.open(busPath);

    // Iteration variables
    string line, description, value;

    // Getting line
    getline(busFile, line);
    
    while(getline(busFile, line)) {
        // save description and value of line
        parseLine(line, description, value);

        // Switch description
        if(description == "LABEL"){
            this->label = value;
        }
        else if(description == "WIDTH"){
            this->width = stoi(value);
        }
        else if(description == "SOURCE"){
            this->source = value;
        }
        else{
            cerr << "ERROR: In file " << busPath << " attribute " << description << " not implemented " << endl;
        }
    }
}