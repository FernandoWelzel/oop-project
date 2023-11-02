#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include "component.hpp"

#include <iostream>

using namespace std;

class Display: public Component{
public:
    int refresh_rate;
    
    string source;

    Component *sourceP;

    // Constructor
    Display(string displayPath);
    // Destructor
    ~Display();

    // Display should knows who has been connected to it: method? TODO
    int simulate(){
        cout << "Temporary message - Display simulation method" << endl;
        
        return 0;
    }
    
    void read(){
        cout << "Temporary message - Display read method" << endl;
    }
};




#endif