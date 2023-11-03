#include <string>

#include "parse.hpp"

using namespace std;

// Simple function to get DESCRIPION: VALUE from each component line
void parseLine (string line, string& description, string& value) {
    // Find colon position
    size_t colonPos = line.find(':');

    // Update strings accordingly
    description = line.substr(0, colonPos);
    value = line.substr(colonPos + 2);
}

void parseExecution(string line, string& operation, double& operand_A, double& operand_B){
    // Find end of command
    size_t spacePos = line.find(' ', 0);
    // Operation to be made
    operation = line.substr(0, spacePos);
    
    // Defining operands
    size_t separation = line.find(' ', spacePos+1);         // Space between operands
    operand_A = stof(line.substr(spacePos, separation));    // First operand
    operand_B = stof(line.substr(separation, line.back())); // Second operand
}