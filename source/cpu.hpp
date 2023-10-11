#ifndef _CPU_HPP_
#define _CPU_HPP_

#include "component.hpp"

class CPU: public Component{
public:
    int cores;
    int frequency;
    int reg;
    // CPU should execute a program
    void execute();
    void read();
};

#endif