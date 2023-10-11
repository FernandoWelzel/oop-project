/*
Include used for class descritpion on the project
*/

#include <iostream>
#include <sstream>
using namespace std;

typedef struct DataValue
{
    double value;
    bool valid;
} DataValue;

class Platform{
public:
    Component component;
    void simulate();
        // Platform should handle all the bindings: method? TODO  
};

class Component{
public:
    string label;
    virtual void simulate(); 
};

class Display: public Component{
private: 
    int refresh_rate;
    // Display should knows who has been connected to it: method? TODO
};

class CPU: public Component{
public:
    int cores;
    int frequency;
    int reg;
    // CPU should execute a program
    void execute();
    void read();
};

class BaseData: public Component{
    // BaseData should knows who has been connected to it: method? TODO
    void read();
};

class Bus: public BaseData{
public:
    int width; 
    int counter;
    bool status; // TRUE == Ready, FALSE == pending 
    // Bus should knows who has been connected to it: method? TODO  
};

class Memory: public BaseData{ // Circular Buffer
public:
    int size;
    int access_time;
    void store();
    // Memory can tell the label of its source
    // Memory should knows who has been connected to it: method? TODO 
};