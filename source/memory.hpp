#ifndef _MEMORY_HPP_
#define _MEMORY_HPP_

#include "component.hpp"
#include "basedata.hpp"

class Memory: public BaseData{ // Circular Buffer
public:
    int size;
    int access_time;
    string source;
    void store();
    void simulate(){
        cout << "Temporary message - memory simulation method" << endl;
    };
    
    // Constructor
    Memory(string memoryPath);
    // Destructor
    ~Memory();
};

#endif