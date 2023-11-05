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

    // Defining component type
    this->type = CPU_T;

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
            ifstream programFile;
            programFile.open(value);

            string instructionLine;

            while(getline(programFile, instructionLine)) {
                // Creating new instuction
                Instruction *newInstruction = new Instruction(instructionLine);

                // Adding instruction to program
                program.push_back(*newInstruction); 
            }

            programCounter = program.begin();

            programFile.close();
        }
        else {
            cerr << "ERROR: In file " << cpuPath << " attribute " << description << " not implemented yet" << endl; 
        }
    }

    // Close file
    cpuFile.close();
}

// Executes "frequency" instructions and writes values to FIFO
int CPU::simulate(bool verboseFlag) {
    // Prints verbose
    if(verboseFlag) {
        cout << "CPU: " << label << endl;
        cout << "    CORES: " << cores << endl;
    }

    // Execute each instruction
    for(int i = 0; i < frequency; i++) {
        writeReg(execute());
    }

    return 0;
}

// Reads one of the values of the FIFO
DataValue CPU::read() {
    return readReg();
}

// Executes one instruction and increments program counter
double CPU::execute(){
    double result = programCounter->execute();

    // Update program counter if not in the end
    if(programCounter < program.end()) {
        ++programCounter;
    }

    return result; 
}

// Writes value to internal FIFO register
void CPU::writeReg(double value){
    reg.push_back(value);
}

// Reads value from internal FIFO register
DataValue CPU::readReg(){
    double value = reg.front();

    bool valid = !regIsEmpty();

    DataValue frontData = DataValue(value, valid);

    // Removes first element
    reg.pop_front();

    return frontData;
}

// Returns 1 is FIFO is empty
bool CPU::regIsEmpty() {
    return reg.size() == 0;
}

Instruction::Instruction(string instructionLine){
    // Find operation separation space
    size_t spacePos = instructionLine.find(' ', 4);

    // Getting instruction from the first charatecter
    type = (instructionType)instructionLine[0];

    operandA = stof(instructionLine.substr(4, spacePos));
    operandB = stof(instructionLine.substr(spacePos, instructionLine.back()));
}

double Instruction::execute() {
    double result;
    
    switch (type)
    {
    case ADD_INST:
        result = operandA + operandB;
        break;
    
    case SUB_INST:
        result = operandA - operandB;
        break;
    
    case MUL_INST:
        result = operandA * operandB;
        break;
    
    case DIV_INST:
        result = operandA / operandB;
        break;
    
    default:
        cerr << "ERROR: Operation " << type << " not implemented" << endl;
        break;
    }

    return result;
}