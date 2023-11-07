#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "component.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

typedef enum {
    ADD_INST = 'A',
    SUB_INST = 'S',
    MUL_INST = 'M',
    DIV_INST = 'D'
} instructionType;

class Instruction {
public:
    double operandA;
    double operandB;

    instructionType type;

    Instruction(string instructionLine);

    double execute();
};

class CPU: public Component {
public:
    int cores;
    int frequency;
    
    list<double> reg;

    vector<Instruction> program;

    vector<Instruction>::iterator programCounter;

    // Constructor
    CPU(string cpuPath);

    // Destructor
    ~CPU();

    // CPU should execute a program
    double execute();

    int simulate(bool verboseFlag);

    DataValue read();

    void writeReg(double value);

    DataValue readReg();

    bool regIsEmpty();
};

#endif