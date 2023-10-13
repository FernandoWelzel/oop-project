#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "component.hpp"

class CPU: public Component{
private:
    int cores;
    int frequency;
    int reg;

public:
    // Constructor
    CPU(string cpuPath);

    // CPU should execute a program
    void execute();
    void read();
    void simulate();
};

#endif