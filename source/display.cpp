#include <string>
#include <fstream>
#include <iostream>

#include "display.hpp"
#include "parse.hpp"

using namespace std;

Display::Display(string displayPath){
    // Open the file
    ifstream displayFile;
    displayFile.open(displayPath);

    // Iteration variables
    string line, description, value;

    // Getting line
    getline(displayFile, line);
    
    while(getline(displayFile, line)) {
        // save description and value of line
        parseLine(line, description, value);

        // Switch description
        if (description == "REFRESH"){
            this->refresh_rate = stoi(value);
        }            
        else if (description == "SOURCE"){
            this->source = value;
        }
        else{
            cerr << "ERROR: In file " << displayPath << " attribute " << description << " not implemented " << endl;
        }
        displayFile.close();
    }
}
