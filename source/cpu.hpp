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

    // Destructor
    ~CPU();

    // CPU should execute a program
    float execute(string programPath);

    void simulate();

    void read(){
        // TODO
        cout << "Temporary message - cpu read method" << endl;
    };
};

#endif