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