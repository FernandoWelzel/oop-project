#include <string>
#include <fstream>
#include <iostream>

#include "memory.hpp"
#include "parse.hpp"

using namespace std;

Memory::Memory(string memoryPath){
    // Open the file
    ifstream memoryFile;
    memoryFile.open(memoryPath);

    // Iteration variables
    string line, description, value;

    // Getting line
    getline(memoryFile, line);
    
    while(getline(memoryFile, line)) {
        // save description and value of line
        parseLine(line, description, value);

        // Switch description
        if (description == "LABEL"){
            this->label = value;
        }            
        else if (description == "SIZE"){
            this->size = stoi(value); 
        }
        else if (description == "ACCESS"){
            this->access_time = stoi(value);
        }
        else if (description == "SOURCE"){
            this->source = value;
        }
        else{
            cerr << "ERROR: In file " << memoryPath << " attribute " << description << " not implemented " << endl;
        }
    }
    memoryFile.close();
}
