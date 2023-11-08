#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "display.hpp"
#include "parse.hpp"
#include "component.hpp"
#include "formating.hpp"

using namespace std;

Display::Display(string displayPath){
    // Open the file
    ifstream displayFile;
    displayFile.open(displayPath);

    // Iteration variables
    string line, description, value;

    // Getting line
    getline(displayFile, line);

    // Defining component type
    this->type = DISPLAY_T;
    
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
            ostringstream errorString;

            errorString << "In file " << displayPath << " attribute " << description << " not implemented ";

            throw runtime_error(errorString.str());
        }
    }

    displayFile.close();
}

Display::~Display(){};

int Display::simulate(bool verboseFlag){
    // Print verbose
    if(verboseFlag) {
        COLOR("Display simulating", YELLOW_TEXT);
    }

    DataValue readData = sourceP->read();       // Declaration of variable  
    if ( this->react % this->refresh_rate != 0 ){
        this->react++;
        cout << "Impossible to simulate due to Refresh Rate." << endl;  
        return 0;
    }
    else {
        while(readData.valid){
            DISPLAY_TEXT(readData.value);
            readData = sourceP->read();
        }
    }        
    return 0;
}