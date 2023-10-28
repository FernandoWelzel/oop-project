#include "../../source/parse.hpp"

#include <gtest/gtest.h>

#include <string>

usign namespace std;

// The fixture for testing class Foo.
class parseTest : public testing::Test {
   protected:
      string description, value;
};

// Tests that the parseLine function for simple cases.
TEST_F(parseTest, simpleParse) {
   // Storing values of line in string attributes of class parseTest
   parseLine("TYPE: CPU", description, value);

   // Checking values in string
   EXPECT_EQ(description, "TYPE");
   EXPECT_EQ(value, "CPU");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}