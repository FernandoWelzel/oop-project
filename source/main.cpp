#include <iostream>

#include "platform.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // TODO: Add option support
    if(argc != 2) {
        cerr << "Wrong number of arguments - Received: " << argc << " Expecting: 1" << endl;
    }

    // Constructing platform from file
    Platform myPlatform(argv[1]);
    
    // myPlataform.build();

    // myPlataform.simulate();
    
    return 0;
}
