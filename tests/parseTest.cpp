#include "parse.hpp"

#include <string>
#include <cassert>

int main(int argc, char **argv) {

   string description, value;

   parseLine("TYPE: CPU", description, value);

   assert(description == "TYPE");
   assert(value == "CPU");

   return 0;
}