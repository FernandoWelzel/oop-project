#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "basedata.hpp"

class Memory: public BaseData{ // Circular Buffer
public:
    int size;
    int access_time;
    void store();
    // Memory can tell the label of its source
    // Memory should knows who has been connected to it: method? TODO 
};

#endif