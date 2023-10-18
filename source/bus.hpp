#ifndef _BUS_HPP_
#define _BUS_HPP_
#include "component.hpp"
#include "basedata.hpp"

class Bus: public BaseData{
public:
    int width;
    string source; 
    int counter;
    bool status; // TRUE == Ready, FALSE == pending  
    void simulate(){
        cout << "simulation operation on Bus" << endl; // TODO - find a way to solve this nonsense 
    };
    void read(){};
    // Constructor
    Bus(string busPath);
    // Destructor
    ~Bus();
};

#endif