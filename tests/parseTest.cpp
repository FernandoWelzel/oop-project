#include "parse.hpp"
#include <gtest/gtest.h>

#include <string>

// Simple test - Try to parse a TYPE
TEST(parseTest, parseType)
{
    string description, value;

    parseLine("TYPE: CPU", description, value);

    ASSERT_EQ(description == "TYPE", 1) << "Type description not parsed correctly";
    ASSERT_EQ(value == "CPU", 1) << "Type label not parsed correctly";
}

// Simple test - Try to parse a LABEL with spaces
TEST(parseTest, parseLabel)
{
    string description, value;

    parseLine("LABEL: My bus 1", description, value);

    ASSERT_EQ(description == "LABEL", 1) << "Label description not parsed correctly";
    ASSERT_EQ(value == "My bus 1", 1) << "Label value not parsed correctly";
}

// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
