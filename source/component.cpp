#include <string>
#include <fstream>
#include <iostream>

#include "component.hpp"

using namespace std;

string Component::getLabel() {
    return this->label;
}

string Component::getProgram() {
    return this->program;
}