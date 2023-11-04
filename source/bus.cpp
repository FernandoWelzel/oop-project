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

DataValue Bus::get(list<DataValue> _list, int counter){

    auto itr = _list.begin();
    advance(itr, counter);
    DataValue& element = *itr;

    while(itr != _list.end()){
        // cout << "on Get - While" << endl;
        if (itr->valid){
            // cout << "Found valid value" << endl;
            // cout << "Value transmitted: " << element.value << endl;
            return element;
            break;            
        }
        itr++;
    }
    // cout << "Did NOT Found valid value" << endl;
    // cout << "Value transmitted: " << element.value << endl;

    return element;
}