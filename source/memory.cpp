#include <string>
#include <fstream>
#include <iostream>

#include "memory.hpp"
#include "parse.hpp"
#include "queue.hpp"

using namespace std;

Memory::Memory(string memoryPath) {
    // Open the file
    ifstream memoryFile;
    memoryFile.open(memoryPath);

    // Iteration variables
    string line, description, value;

    // Getting line
    getline(memoryFile, line);

    // Defining component type
    this->type = MEMORY_T;
    
    while(getline(memoryFile, line)) {
        // save description and value of line
        parseLine(line, description, value);

        // Switch description
        if (description == "LABEL"){
            this->label = value;
        }            
        else if (description == "SIZE"){
            this->size = stoi(value); 
        }
        else if (description == "ACCESS"){
            this->accessTime = stoi(value);
        }
        else if (description == "SOURCE"){
            this->source = value;
        }
        else{
            cerr << "ERROR: In file " << memoryPath << " attribute " << description << " not implemented " << endl;
        }
    }

    // Initializing queue
    memory = new Queue<double>(this->size);

    memoryFile.close();
}

Memory::~Memory() {
    delete memory;
}

int Memory::simulate(bool verboseFlag) {
    if(accessCounter == accessTime) {
        // Getting value from source
        DataValue readData = sourceP->read();

        while(readData.valid) {
            // Storing value in memory
            memory->enQueue(readData.value);

            // Updating data value
            readData = sourceP->read();
        }
    }

    // Incrementing counter
    accessCounter = (accessCounter + 1)%(accessTime);

    return 0;
}

DataValue Memory::read() {
    // Checking if memory is empty
    bool readValid = !memory->isEmpty();
    
    if(readValid) {
        // Getting value from memory
        double readValue = memory->deQueue();

        // Creating new return data
        DataValue readData(readValue, readValid);
    
        return readData;
    }
    
    // Return invalid
    return DataValue(0, readValid);
}
