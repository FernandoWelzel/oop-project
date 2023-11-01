#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include "component.hpp"

#include <iostream>

using namespace std;

class Memory: public Component { // Circular Buffer
public:
    int size;
    int access_time;
    
    string source;
    
    Component *sourceP;

    void store();
    
    int simulate(){
        cout << "Temporary message - memory simulation method" << endl;

        return 0;
    };

    void read(){
        cout << "Temporary message - memory read method" << endl;
    };
    
    // Constructor
    Memory(string memoryPath);
    // Destructor
    ~Memory();
};

#endif