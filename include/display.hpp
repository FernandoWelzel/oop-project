#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include "component.hpp"
#include <iostream>

using namespace std;

class Display: public Component{
private:
    int react = 0;
public:
    int refresh_rate;
    
    string source;

    Component *sourceP;

    // Constructor
    Display(string displayPath);
    // Destructor
    ~Display();

    // Methods
    int simulate();
    virtual DataValue read();
};




#endif