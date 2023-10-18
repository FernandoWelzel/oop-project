#ifndef _BASEDATA_HPP_
#define _BASEDATA_HPP_
#include "component.hpp"

class BaseData: public Component{
    // BaseData should knows who has been connected to it: method? TODO
protected:
    string source;
    void read();
};

#endif