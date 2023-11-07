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

int Display::simulate(){
    if ( this->react % this->refresh_rate != 0 ){
        this->react++;
        cout << "Impossible to simulate due to Refresh Rate." << endl;  
        return 0;
    }
    else{
        read();
    }
    cout << "Temporary message - Display simulation method" << endl;
        
    return 0;
}

DataValue Display::read(){
    cout << "In read method of Display" << endl;
    DataValue readData(sourceP->read());
    // DataValue readData(sourceP->read()); // Storing value read from source
    cout << "DATA obtained: " << readData.value << endl;
    if ( readData.valid ){
        cout << "DISPLAY - Value read: "<< readData.value << endl;
        this->read(); // Continue to read 
    }
    else{ // invalid DataValue
        return DataValue(0, false);
    }
    return DataValue(0, false);
}
