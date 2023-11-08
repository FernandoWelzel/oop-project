#include <iostream>
#include <string>
#include <fstream> 
#include <sstream>

#include "bus.hpp"
#include "parse.hpp"
#include "formating.hpp"

using namespace std;

Bus::Bus(string busPath){
    // Open the file
    ifstream busFile;
    busFile.open(busPath);

    if(!busFile){
        cout << "ERROR opening file" << endl;
    }
    // Iteration variables
    string line, description, value;

    // Getting line
    getline(busFile, line);

    // Defining component type
    this->type = BUS_T;
    
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
            ostringstream errorString;

            errorString << "In file " << busPath << " attribute " << description << " not implemented ";

            throw runtime_error(errorString.str());
        }
    }

    busFile.close();
}

Bus::~Bus(){}

DataValue Bus::read(){
    DataValue readData(0, false);

    this->counter++;

    // Check ready vector not empty then return first
    if (!ready.empty()){
        // Getting value from ready - Setting validity
        readData.value = ready[0];
        readData.valid = true;

        ready.erase(ready.begin()); 

        return readData;
    }
    
    return readData;
}   

int Bus::simulate(bool verboseFlag){ 
    if(verboseFlag) {
        COLOR(label << " simulating", YELLOW_TEXT);
    }
    
    // Inserting pending into ready
    ready.insert(ready.end(), pending.begin(), pending.end()); // moves pending to ready

    // Deleting pending
    pending.erase(pending.begin(), pending.end());

    // Initializing data
    DataValue readData(0, false);

    for (int i = 0; i < this->width; i++){
        readData = (sourceP->read());

        if(verboseFlag) {
            if(readData.valid) {
                cout << "Bus read valid data: " << readData.value << endl;
            } else {
                cout << "Bus read invalid data" << endl;
            }
        }

        if (readData.valid){
            pending.insert(pending.end(), readData.value);
        }
        else {
            break;
        }
    }

    if(verboseFlag) {
        // Print ready
        cout << "PENDING: ";
        for(vector<double>::iterator it = pending.begin(); it != pending.end(); ++it) {
            cout << *it <<  ", ";
        }
        cout << endl;

        // Print ready
        cout << "READY: ";
        for(vector<double>::iterator it = ready.begin(); it != ready.end(); ++it) {
            cout << *it <<  ", ";
        }
        cout << endl;
    }

    return 0;
};
