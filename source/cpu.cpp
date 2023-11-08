#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "cpu.hpp"
#include "parse.hpp"
#include "formating.hpp"

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
                // Adding instruction to program
                program.push_back(Instruction(instructionLine));
            }

            // Adding less NOP instruction to program
            program.push_back(Instruction(NOP_INST, 0, 0));

            programCounter = program.begin();

            programFile.close();
        }
        else {
            ostringstream errorString;

            errorString << "In file " << cpuPath << " attribute " << description << " not implemented yet";

            throw runtime_error(errorString.str()); 
        }
    }

    // Setting first active core
    activeCore = 0;

    // Close file
    cpuFile.close();
}

CPU::~CPU() {
}

// Prints register values in sequence
void CPU::printReg() {
    // Print register
    cout << "REG: ";
    for(list<double>::iterator it = reg.begin(); it != reg.end(); ++it) {
        cout << *it <<  " ";
    }
    cout << endl;
}

// Executes "frequency" instructions and writes values to FIFO
int CPU::simulate(bool verboseFlag) {
    // Print verbose
    if(verboseFlag) {
        COLOR(label << " simulating", YELLOW_TEXT);
        cout << "Active CORE: " << activeCore+1 << endl;
    }

    // Execute each instruction
    for(int i = 0; i < frequency; i++) {
        execute(verboseFlag);
    }

    if(verboseFlag) {
        printReg(); 
    }

    return 0;
}

// Reads one of the values of the FIFO
DataValue CPU::read() {
    return readReg();
}

// Executes one instruction and increments program counter
double CPU::execute(bool verboseFlag){
    double result = 0;   

    if(programCounter < program.end() - 1) {
        // Standart program execution
        result = programCounter->execute(verboseFlag);
        ++programCounter;

        writeReg(result);
    } else if(activeCore < cores - 1) {
        // Start processing with next core
        programCounter = program.begin();
        activeCore++;

        // Process first instruction
        result = programCounter->execute(verboseFlag);
        ++programCounter;
    
        writeReg(result);
    }

    return result; 
}

// Writes value to internal FIFO register
void CPU::writeReg(double value){
    reg.push_back(value);
}

// Reads value from internal FIFO register
DataValue CPU::readReg(){
    // Quit loop if not valid
    if(regIsEmpty()) {
        return DataValue(0, false);
    }
    
    double value = reg.front();

    DataValue frontData = DataValue(value, true);

    // Removes first element
    reg.pop_front();

    return frontData;
}

// Returns 1 is FIFO is empty
bool CPU::regIsEmpty() {
    return reg.empty();
}

// Constructor from a given instruction line
Instruction::Instruction(string instructionLine){
    // Find operation separation space
    size_t spacePos = instructionLine.find(' ', 4);

    // Getting instruction from the first charatecter
    type = (instructionType)instructionLine[0];

    operandA = stof(instructionLine.substr(4, spacePos));
    operandB = stof(instructionLine.substr(spacePos, instructionLine.back()));
}

// Default constructor
Instruction::Instruction(instructionType _type, double _operandA, double _operandB) :
    type(_type),
    operandA(_operandA),
    operandB(_operandB) {}

// Execute each instruction -> Returning the result
double Instruction::execute(bool verboseFlag) {
    // Map for name conversion
    map<instructionType, string> inst2string = {
        {ADD_INST, "ADD"},
        {SUB_INST, "SUB"},
        {MUL_INST, "MUL"},
        {DIV_INST, "DIV"},
        {NOP_INST, "NOP"}    
    };

    if(verboseFlag) {
        cout << "Executing instruction: " << inst2string[type] << " " << operandA << " " << operandB << endl;
    }
    
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
    
    case NOP_INST:
        result = 0;
        break;
    
    default:
        throw runtime_error("Operation not implemented");
    }

    return result;
}