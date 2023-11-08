#ifndef _BUS_HPP_
#define _BUS_HPP_

#include "component.hpp"

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  

using namespace std;

class Bus: public Component {
public:
    int width;
    int counter = 0;

    vector<double> pending;
    vector<double> ready;

    string source;

    Component *sourceP;

    // Constructor
    Bus(string busPath);

    // Destructor
    ~Bus();

    // Methods
    int simulate(bool verboseFlag);

    DataValue read();

};

#endif