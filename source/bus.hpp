#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "component.hpp"
#include "basedata.hpp"

class Bus: public BaseData{
public:
    int width; 
    int counter;
    bool status; // TRUE == Ready, FALSE == pending 
    // Bus should knows who has been connected to it: method? TODO  
};

#endif