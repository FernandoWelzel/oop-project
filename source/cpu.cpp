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

void CPU::read() {
    return;
}


float CPU::execute(string programPath){ // Return Type to be optimized according to values of operation
// Open the file
    ifstream programFile;
    programFile.open(programPath);

    // Iteration variables
    string line, operation;
    float operand_A, operand_B;
    // Getting unused TYPE line
    getline(programFile, line);

    // Store operation and operands from line
    parseExecution(line, operation, operand_A, operand_B);

    // Executing operation
    if(operation == "ADD") {
        return operand_A + operand_B;
    }
    else if(operation == "SUB"){
        return operand_A - operand_B; 
    }
    else if(operation == "MUL") {
        return operand_A * operand_B;
    }
    else if(operation == "DIV") {
        return operand_A / operand_B; 
    }
    else {
        cerr << "ERROR: In file " << programPath << " operation " << operation << " not implemented " << endl; 
    }

    // Close file
    programFile.close();
    return 0;
    // TODO - find a way to delete line from program file or to be able to loop until all instructions have passed.
}