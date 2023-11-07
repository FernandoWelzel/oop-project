#include "bus.hpp"
#include "component.hpp"
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>



// Simple test - try to read a value from bus
TEST(busTest, busRead)
{
    // Creating DataValue variables
    DataValue test(2.01, false);
    DataValue test1(3.02, false);
    DataValue test_out(0, false);
    // Creating Bus
    Bus *myBus = new Bus("data/bus1.txt");
  
    // Inserting variable
    myBus->variable.push_front(test);
    myBus->variable.push_front(test1);
 
    // Calling method
    // DataValue test_out;
    test_out = myBus->read();
 
    // Hard coded verification
    cout << "Value obtained after read operation: " << test_out.value << endl;
}

TEST(busTest, busSimulate)
{
    // Creating DataValue variables
    DataValue test(2.01, true);
    DataValue test1(3.02, false);
    DataValue test3(4.03, false);
    DataValue test4(5.04, false);
    // Creating Bus
    Bus *myBus = new Bus("data/bus1.txt");
    myBus->width = 2;
    // Inserting variable
    myBus->variable.push_front(test);
    myBus->status.push_back(false);
    myBus->variable.push_front(test1);
    myBus->status.push_back(false);
    myBus->variable.push_front(test3);
    myBus->status.push_back(false);
    myBus->variable.push_front(test4);
    myBus->status.push_back(false);

    myBus->simulate();

}



// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
