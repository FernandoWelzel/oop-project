#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_
#include "component.hpp"

class Display: public Component{
private: 
    int refresh_rate;
    // Display should knows who has been connected to it: method? TODO
};

#endif