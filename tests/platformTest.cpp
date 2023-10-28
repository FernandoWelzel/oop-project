#include "platform.hpp"
#include <gtest/gtest.h>

#include <string>

// Create platform - Build test
TEST(platformTest, buildTest)
{
    Platform myPlatform("./tests/data/platform.txt");
}

// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
