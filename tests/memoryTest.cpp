#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>
#include <string>

#include "memory.hpp"

TEST(memoryTest, basicTest)
{
    Memory myMemory("data/mem1.txt");

    // First value should be one after the overwrite
    ASSERT_EQ(myMemory.accessTime, 2);

    ASSERT_EQ(myMemory.read().valid, false);

    // Writing value to memory
    myMemory.memory->enQueue(1);

    cout << "Front: " << myMemory.memory->front << endl;
    cout << "Rear: " << myMemory.memory->rear << endl;

    myMemory.memory->enQueue(1);

    cout << "Front: " << myMemory.memory->front << endl;
    cout << "Rear: " << myMemory.memory->rear << endl;

    myMemory.memory->enQueue(1);

    cout << "Front: " << myMemory.memory->front << endl;
    cout << "Rear: " << myMemory.memory->rear << endl;

    ASSERT_EQ(myMemory.read().valid, true);
    
    cout << "Front: " << myMemory.memory->front << endl;
    cout << "Rear: " << myMemory.memory->rear << endl;

    ASSERT_EQ(myMemory.read().valid, true);

    cout << "Front: " << myMemory.memory->front << endl;
    cout << "Rear: " << myMemory.memory->rear << endl;

    ASSERT_EQ(myMemory.read().valid, true);

    cout << "Front: " << myMemory.memory->front << endl;
    cout << "Rear: " << myMemory.memory->rear << endl;

    ASSERT_EQ(myMemory.read().valid, false);
}

// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
