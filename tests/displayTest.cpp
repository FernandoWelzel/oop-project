#include "display.hpp"
#include "bus.hpp"
#include "component.hpp"
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>



// Simple test - try read method of display
TEST(displayTest, displayRead)
{
    // Creating Bus - to read from
    Bus *myBus = new Bus("data/bus1.txt");
    // Creating Display
    Display *myDisplay = new Display("data/display.txt");
    cout << "Display connected to: " << myDisplay->source << endl;
    // Creating DataValue variables
    DataValue test(2.01, true);
    DataValue test1(3.02, true);
    DataValue test3(4.03, true);
    DataValue test4(5.04, true);

    myBus->variable.push_front(test);
    myBus->status.push_back(true);
    myBus->variable.push_front(test1);
    myBus->status.push_back(true);
    myBus->variable.push_front(test3);
    myBus->status.push_back(true);
    myBus->variable.push_front(test4);
    myBus->status.push_back(true);

    cout << "Created BUS and DISPLAY - on test" << endl;
    myDisplay->read();
    cout << "Operation Completed" << endl;

}

// Simple test - try to simulate display
// TEST(displayTest, displaySimulate)
// {
// 
// }



// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
