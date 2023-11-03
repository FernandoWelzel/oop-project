#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include "component.hpp"

#include "queue.hpp"

#include <iostream>

using namespace std;

class Memory: public Component { // Circular Buffer
public:
    int size;
    int accessTime;

    int accessCounter;

    string source;
    
    Component *sourceP;

    Queue<double> *memory;

    void store();
    
    int simulate();

    DataValue read();
    
    // Constructor
    Memory(string memoryPath);
    
    // Destructor
    ~Memory();
};

#endif