#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>

#include "parse.hpp"
#include "cpu.hpp"

// Simple test - Try to parse a TYPE
TEST(CPUTest, constructorTest)
{
    CPU *myCPU = new CPU("data/cpu1.txt");

    // Getting first instruction
    vector<Instruction>::iterator myProgramCounter = myCPU->programCounter;

    // Hardcoded first expected results 
    vector<double> expectedResults = {
        5, 3.3, 15.006, 4.2, 50, 30.3, (double)(50.002)*(double)(30), 4.02
    };

    // Declaring iteration for results
    vector<double>::iterator it;

    // TODO: Fix test for doubles
    for(it = expectedResults.begin(); it != expectedResults.end(); ++it, ++myProgramCounter) {
        // cout << myProgramCounter->execute() << endl;
        // ASSERT_TRUE(myProgramCounter->execute() == *it);
    }
}

// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
