#include <iostream>

#include "platform.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // TODO: Add option support

    if(argc != 2) {
        cerr << "Wrong number of arguments - Received: " << argc << " Expecting: 1" << endl;
    }

    Platform myPlatform(argv[1]);
    // Memory Parser testing
    cout << "Label of first component is: "  << myPlatform.components[0]->getLabel() << endl;
    cout << "Label of second component is: "  << myPlatform.components[1]->getLabel() << endl;
    // Bus Parser testing
    cout << "Label of third component is: "  << myPlatform.components[2]->getLabel() << endl;
    cout << "Label of fourth component is: "  << myPlatform.components[3]->getLabel() << endl;
    // CPU Parser testing
    cout << "Label of fifth component is: "  << myPlatform.components[4]->getLabel() << endl;
    cout << "Label of sixth component is: "  << myPlatform.components[5]->getLabel() << endl;
    // DISPLAY Parser testing
    cout << "Label of seventh component is: "  << myPlatform.components[6]->getLabel() << endl;
    // myPlataform.build();

    // myPlataform.simulate();
    
    return 0;
}
