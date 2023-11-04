#include <iostream>
#include <unistd.h>
#include <getopt.h>

#include "platform.hpp"

using namespace std;

void printUsage(char* argv0) {
    cout << "Usage: " << argv0 << " [options] filename" << endl;
    cout << "Options:" << endl;
    cout << "  -h  Display this help message" << endl;
    cout << "  -v  Components print message each time they simulates" << endl;
}

int main(int argc, char* argv[]) {
    int option;

    // Default values for options
    int helpFlag = 0;
    int verboseFlag = 0;

    // Parse command-line options using getopt
    while ((option = getopt(argc, argv, "hv")) != -1) {
        switch (option) {
            case 'v':
                verboseFlag = 1;
                break;

            case 'h':
                helpFlag = 1;
                break;

            default:
                // Printing error/help message
                cout << endl;
                printUsage(argv[0]);
                
                cout << endl;
                cerr << "ERROR: Unknown or malformated option" << endl;

                exit(1);
        }
    }

    // Prints help if necessary
    if (helpFlag) {
        printUsage(argv[0]);
        return 0;
    }

    // Constructing platform from file
    Platform myPlatform(argv[argc-1]);
    
    // Binding components of platform
    myPlatform.build();

    // Simulate all components
    myPlatform.simulate();
    
    return 0;
}
