#ifndef _PLATFORM_
#define _PLATFORM_
#include "component.hpp"

class Platform{
public:
    Component component;
    void simulate();
        // Platform should handle all the bindings: method? TODO  
};

#endif