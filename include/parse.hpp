#ifndef _PARSE_HPP_
#define _PARSE_HPP_

#include <string>

using namespace std;

void parseLine (string line, string& description, string& value);
void parseExecution(string line, string& operation, float& operand_A, float&operand_B);

#endif
