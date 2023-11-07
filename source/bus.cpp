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
            cerr << "ERROR: In file " << busPath << " attribute " << description << " not implemented " << endl;
        }
    }
    busFile.close();
}

Bus::~Bus(){}

DataValue Bus::read(){
    DataValue readData = (sourceP->read()); // creates variable
    this->counter++;
    if (!ready.empty()){                    // ready vector not empty
        readData.value = ready[0];          // changing value
        ready.erase(ready.begin());         // 
        return readData;
    }
    else{
        return DataValue(0, false);
    }
}   

int Bus::simulate(){ 
    this->ready = this->pending; // moves pending to ready
    int i;  // iterator
    DataValue readData(0, false);

    for (i = 0; i <= this-> width; i++){
        readData = (sourceP->read());
        pending.insert(pending.end(), readData.value);
        if (!readData.valid){
            break;
        }
    }
    return 0;
};
