#ifndef _BUS_HPP_
#define _BUS_HPP_

#include "component.hpp"

class Bus: public Component {
public:
    int width;
    string source; 
    int counter;
    bool status; // TRUE == Ready, FALSE == pending

    void simulate(){
        // TODO
        cout << "Temporary message - memory simulation method" << endl;
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