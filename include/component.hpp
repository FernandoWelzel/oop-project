#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

using namespace std;

typedef enum {CPU_T, BUS_T, DISPLAY_T, MEMORY_T} componentType;

class DataValue {
public:
    double value;
    
    bool valid;

    DataValue(double _value, bool _valid) : value(_value), valid(_valid) {};
};

class Component{
protected:
    string label;
    string program;

public:
    componentType type;

    virtual int simulate() = 0;
    
    virtual DataValue read() = 0;
    
    string getLabel();
    string getProgram();
};

#endif