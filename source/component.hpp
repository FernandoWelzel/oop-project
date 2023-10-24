#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

using namespace std;

class Component{
protected:
    string label;
    string program;

public:
    virtual void simulate() = 0;
    virtual void read() = 0;
    
    string getLabel();
    string getProgram();
};

#endif