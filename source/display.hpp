#ifndef _DISPLAY_HPP_
#define _DISPLAY_HPP_

#include "component.hpp"

class Display: public Component{
public:
    // Constructor
    Display(string displayPath);
    // Destructor
    ~Display();

private: 
    int refresh_rate;
    string source;
    // Display should knows who has been connected to it: method? TODO
    void simulate(){
        cout << "Temporary message - Display simulation method" << endl;
    }
    void read(){
        cout << "Temporary message - Display read method" << endl;
    }
};




#endif