#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

#include <vector>
#include <string>

#include "component.hpp"
#include "cpu.hpp"

using namespace std;

class Platform{
public:
    // Creating vector of pointers to Components
    vector<Component*> components;

    Platform(string platformPath);

    ~Platform(); 

    void build(); 

    void simulate();

    void addComponent(string componentPath);
};

#endif