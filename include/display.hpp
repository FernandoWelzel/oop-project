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

    // Display should knows who has been connected to it: method? TODO
    int simulate(bool verboseFlag);
    DataValue read(){
        return DataValue(0, false);
    };
};




#endif