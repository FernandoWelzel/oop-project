#include <iostream>
#include <string>
#include <fstream>

#include "platform.hpp"
#include "cpu.hpp"

using namespace std;

void parseLine (string line, string& description, string& value) {
    // Find colon position
    size_t colonPos = line.find(':');

    // Update strings accordingly
    description = line.substr(0, colonPos);
    value = line.substr(colonPos + 2);
}

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
        CPU* newCPU = new CPU();

        // Adding to vector
        components.push_back(newCPU);
    } 
    // else if (value == "MEMORY") {
    // } else if (value == "DISPLAY") {
    // } else if (value == "BUS") {
    // } else if (value == "PROGRAM") {} 
    else {
        cerr << "ERROR: Component " << value << " not supported yet" << endl;
    }

    // Close the file
    componentFile.close();
}