#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

#include <string>

using namespace std;

class Component{
public:
    string label;
    
    virtual void simulate() = 0;
};

#endif