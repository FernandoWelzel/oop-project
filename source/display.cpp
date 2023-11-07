#include <string>
#include <fstream>
#include <iostream>

#include "display.hpp"
#include "parse.hpp"
#include "component.hpp"

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
            cerr << "ERROR: In file " << displayPath << " attribute " << description << " not implemented " << endl;
        }
    }

    displayFile.close();
}

Display::~Display(){};

int Display::simulate(bool verboseFlag){
    // Print verbose
    if(verboseFlag) {
        cout << "Display simulated: " << label << endl; 
    }

    DataValue readData = sourceP->read();       // Declaration of variable  
    if ( this->react % this->refresh_rate != 0 ){
        this->react++;
        cout << "Impossible to simulate due to Refresh Rate." << endl;  
        return 0;
    }
    else{
        while(readData.valid){
            cout << "DISPLAY - Value Read:" << readData.value << endl;
            readData = sourceP->read();
    }
    }        
    return 0;
}