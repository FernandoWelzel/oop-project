#include <iostream>

#include "platform.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // TODO: Add option support

    if(argc != 2) {
        cerr << "Wrong number of arguments - Received: " << argc << " Expecting: 1";
    }

    Platform myPlatform(argv[1]);

    cout << "Label of first component is: "  << myPlatform.components[0]->getLabel() << endl;

    // myPlataform.build();

    // myPlataform.simulate();
    
    return 0;
}
