#include <iostream>
#include <string>
#include <fstream>

#include "platform.hpp"
#include "cpu.hpp"
#include "parse.hpp"
#include "memory.hpp"
#include "display.hpp"
#include "bus.hpp"

using namespace std;

Platform::Platform(string platformPath) {
    // Open the file
    ifstream platformFile;
    platformFile.open(platformPath);

    // Check if the file is successfully opened
    if (!platformFile.is_open()) {
        cerr << "ERROR opening the file: " << platformPath << endl;
        return;
    }

    string line;

    // Read each line from the file
    while (getline(platformFile, line)) {
        addComponent(line);
    }

    // Close the file
    platformFile.close();
}

Platform::~Platform() {
    for (auto component : components)
        delete component;
}

void Platform::addComponent(string componentPath) {
    // Open the file
    ifstream componentFile;
    componentFile.open(componentPath);

    // Check if the file is successfully opened
    if (!componentFile.is_open()) {
        cerr << "ERROR: Couldn't open the file: " << componentPath << endl;
        return;
    }

    // Declaring iterators
    string line, description, value;

    // Reading type
    getline(componentFile, line);
    parseLine(line, description, value);

    // Handle malformating
    if(description != "TYPE") {
        cerr << "ERROR: Malformated file: " << componentPath << endl;
        return;
    }

    // Get type of component
    if (value == "CPU") {
        CPU* newCPU = new CPU(componentPath);

        // Adding to vector
        components.push_back(newCPU);
    } 
    else if (value == "MEMORY") {
        Memory* newMemory = new Memory(componentPath);
        
        // Adding to vector
        components.push_back(newMemory);
    }
    else if (value == "DISPLAY") {
        Display* newDisplay = new Display(componentPath);

        // Adding to vector
        components.push_back(newDisplay);
    } 
    else if (value == "BUS") {
        Bus* newBus = new Bus(componentPath);

        // Adding to a vector
        components.push_back(newBus);
    } 
    // else if (value == "PROGRAM") {} 
    else {
        cerr << "ERROR: Component " << value << " not supported yet" << endl;
    }

    // Close the file
    componentFile.close();
}

// Go thought components list and binds components together
void Platform::build() {
    // Checks if list is not empty
    if(components.size() <= 0) {
        cerr << "ERROR: Trying to build an empty platform" << endl;
        return;
    }

    // Creating pointers for each type
    Component *componentP;

    Memory *memoryP;
    Bus *busP;
    Display *displayP;
    
    for(int i = 0; i < components.size(); i++) {
        // Get component from array
        componentP = components[i];

        // Switch type
        switch (componentP->type)
        {
        case MEMORY_T:
            memoryP = dynamic_cast<Memory*>(componentP);

            // Searches for source string and storest component pointer in sourceP
            findLabel(memoryP->source, memoryP->sourceP);
            
            break;
        
        case BUS_T:
            busP = dynamic_cast<Bus*>(componentP);

            // Searches for source string and storest component pointer in sourceP
            findLabel(busP->source, busP->sourceP);

            break;
        
        case DISPLAY_T:
            displayP = dynamic_cast<Display*>(componentP);

            // Searches for source string and storest component pointer in sourceP
            findLabel(displayP->source, displayP->sourceP);
            
            break;
        
        case CPU_T: // No source to bind to
            break;
        
        default:
            cerr << "ERROR: Unknown component type" << endl;
            break;
        }
    }
}

// Go thought components list and returns component with correct label
int Platform::findLabel(string label, Component* &componentP) {
    // Checks if list is not empty
    if(components.size() <= 0) {
        cerr << "ERROR: Trying to find label in empty platform" << endl;
        return 1;
    }

    // Go thought array trying to find label
    for(int i = 0; i < components.size(); i++) {
        if(components[i]->getLabel() == label) {
            componentP = components[i];
            return 0;
        }
    }

    // Return if not in list
    return 1;
}

// Simulates all components in the platform
int Platform::simulate(bool verboseFlag) {
    // Prints verbose
    if(verboseFlag) {
        cout << "Platform" << endl << endl;
    }

    // Runs platform
    while(1) {
        vector<Component*>::iterator it;

        // Iterates simulating each component
        for(it = components.begin(); it != components.end(); ++it) {
            if((*it)->simulate(verboseFlag)) return 1;
        }
    }

    return 0;
}
