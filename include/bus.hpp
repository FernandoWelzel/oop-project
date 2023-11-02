#ifndef _BUS_HPP_
#define _BUS_HPP_

#include "component.hpp"

#include <iostream>

using namespace std;

class Bus: public Component {
public:
    int width;
    int counter;

    bool status; // TRUE == Ready, FALSE == pending

    string source;

    Component *sourceP;
 
    int simulate(){
        // TODO
        cout << "Temporary message - memory simulation method" << endl;
        return 1;
    };

    void read(){
        // TODO
        cout << "Temporary message - memory read method" << endl;
    };
    
    // Constructor
    Bus(string busPath);
    // Destructor
    ~Bus();
};

#endif