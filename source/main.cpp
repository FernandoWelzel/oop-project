#include <iostream>
#include <unistd.h>
#include <getopt.h>

#include "platform.hpp"
#include "formating.hpp"

using namespace std;

// Usage message to be displayed if help required
void printUsage(char* argv0) {
    COLOR("USAGE:" << argv0 << " [options] filename", BLUE_TEXT);
    COLOR("Options:", RESET_COLOR);
    COLOR("  -h         Display this help message", RESET_COLOR);
    COLOR("  -v         Components print message each time they simulates", RESET_COLOR);
    COLOR("  -s [STEPS] Number of simulation steps", RESET_COLOR);
}

// Gets a platform path from the first string, builds it, and simulates it
int main(int argc, char* argv[]) {
    int option;

    // Default values for options
    int helpFlag = 0;
    int verboseFlag = 0;
    int simulationSteps = 10;

    // Parse command-line options using getopt
    while ((option = getopt(argc, argv, "hvs:")) != -1) {
        switch (option) {
            case 'v':
                verboseFlag = 1;
                break;

            case 'h':
                helpFlag = 1;
                break;
            
            case 's':
                cout << "Argument " << optarg << endl;

                simulationSteps = atoi(optarg);
                
                cout << "Simulation steps: " << simulationSteps << endl;

                break;

            default:
                // Printing error/help message
                cout << endl; printUsage(argv[0]); cout << endl;

                ERROR("Unknown of malformated option"); return 1;
        }
    }

    // Prints help if necessary
    if (helpFlag) {
        printUsage(argv[0]);
        return 0;
    }

    string platformPath = argv[argc-1];

    Platform* myPlatformP;

    // Try/Catch for construction and binding
    try {
        INFO("Constructing platform from file: " << platformPath);
        myPlatformP = new Platform(platformPath, simulationSteps); 
    }
    // Catch constructor errors
    catch(const exception& e) {
        ERROR("While constructing platform: " << e.what()); return 1;
    }

    // Tries to bind all components of platform
    try{
        INFO("Building platform");
        myPlatformP->build();
    }
    // Catches build errors
    catch(const exception& e) {
        ERROR("While building platform: " << e.what()); return 1;
    }

    // Tries simulating all components of platform
    try{
        INFO("Platform simulation has started");
        
        // Running main simulation
        myPlatformP->simulate(verboseFlag); 
    }
    // Catches build errors
    catch(const exception& e) {
        ERROR("While simulating platform: " << e.what()); return 1;
    }

    // Returns zero in case of no errors    
    return 0;
}
