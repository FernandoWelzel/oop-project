#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

#include <vector>
#include <string>

#include "component.hpp"
#include "cpu.hpp"
#include "memory.hpp"

using namespace std;

class Platform: public Component {
public:
    // Creating vector of pointers to Components
    vector<Component*> components;

    int simulationSteps;

    Platform(string platformPath, int _simulationSteps);

    ~Platform(); 

    void build(); 

    int simulate(bool verboseFlag);

    DataValue read();

    void addComponent(string componentPath);

    int findLabel(string label, Component* &componentP);
};

#endif