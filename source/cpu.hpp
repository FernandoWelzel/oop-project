#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "component.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef enum {
    ADD_INST = 'A',
    SUB_INST = 'S',
    MUL_INST = 'M',
    DIV_INST = 'D'
} instructionType;

class Instruction
{
public:
    float operandA;
    float operandB;

    instructionType type;

    Instruction(string instructionLine);

    float execute();
};

class CPU: public Component{
public:
    int cores;
    int frequency;
    
    float reg;

    vector<Instruction> program;

    vector<Instruction>::iterator programCounter;

    // Constructor
    CPU(string cpuPath);

    // Destructor
    ~CPU();

    // CPU should execute a program
    float execute();

    void simulate();

    void read();
};

#endif