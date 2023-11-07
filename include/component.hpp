#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

using namespace std;

typedef enum {PLATFORM_T, CPU_T, BUS_T, DISPLAY_T, MEMORY_T} componentType;

class DataValue {
public:
    double value;
    
    bool valid;

    DataValue(double _value, bool _valid) : value(_value), valid(_valid) {};
};

class Component{
protected:
    string label;

public:
    componentType type;

    virtual int simulate(bool verboseFlag) = 0;
    
    virtual DataValue read() = 0;
    
    string getLabel();
    string getProgram();
};

#endif