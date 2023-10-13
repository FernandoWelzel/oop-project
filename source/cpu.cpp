#include <string>
#include <fstream>
#include <iostream>

#include "cpu.hpp"
#include "parse.hpp"

using namespace std;

CPU::CPU(string cpuPath) {
    // Open the file
    ifstream cpuFile;
    cpuFile.open(cpuPath);

    // Iteration variables
    string line, description, value;
    
    // Getting unused TYPE line
    getline(cpuFile, line);

    while(getline(cpuFile, line)) {
        // Store description and value from line
        parseLine(line, description, value);

        // Switch description - TODO: Should probably check values before storing them
        if(description == "LABEL") {
            this->label = value; 
        }
        else if(description == "CORES"){
            this->cores = stoi(value); 
        }
        else if(description == "FREQUENCY") {
            this->frequency = stoi(value);
        }
        else if(description == "PROGRAM") {
            this->program = value; 
        }
        else {
            cerr << "ERROR: In file " << cpuPath << " attribute " << description << " not implemented yet" << endl; 
        }
    }

    // Close file
    cpuFile.close();
}

void CPU::simulate() {
    return;
}