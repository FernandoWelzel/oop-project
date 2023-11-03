#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <iostream>
#include <string>

#include "queue.hpp"

TEST(queueTest, basicTest)
{
    const int queueSize = 4;

    Queue<int> myQueue(queueSize);

    // Writing until overwrite first value
    for(int i = 0; i < queueSize + 1; i++) {
        myQueue.enQueue(i*10);
    }

    // First value should be one after the overwrite
    ASSERT_EQ(myQueue.deQueue(), 10);
}

// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
