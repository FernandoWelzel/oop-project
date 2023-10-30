#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

using namespace std;

typedef enum {CPU_T, BUS_T, DISPLAY_T, MEMORY_T} componentType;

class Component{
protected:
    string label;
    string program;

public:
    componentType type;

    virtual void simulate() = 0;
    virtual void read() = 0;
    
    string getLabel();
    string getProgram();
};

#endif