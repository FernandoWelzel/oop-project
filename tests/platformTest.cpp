#include <gtest/gtest.h>

#include <string>

#include "platform.hpp"
#include "memory.hpp"
#include "bus.hpp"
#include "cpu.hpp"
#include "display.hpp"

// Create platform - Constructor test
// Check if all components are created correctly from the configuration files
TEST(platformTest, constructorTest)
{
    Platform myPlatform("data/platform.txt");

    // Get first component - DRAM 1
    Memory *myMemoryP =  dynamic_cast<Memory*>(myPlatform.components[0]);
    
    // Assert values of DRAM 1
    ASSERT_TRUE(myMemoryP->getLabel() == "DRAM 1");
    ASSERT_TRUE(myMemoryP->size == 32);
    ASSERT_TRUE(myMemoryP->access_time == 2);
    ASSERT_TRUE(myMemoryP->source == "My bus 1");
    
    // Get second component - DRAM 2
    myMemoryP = dynamic_cast<Memory*>(myPlatform.components[1]);
    
    // Assert label from each component in order
    ASSERT_TRUE(myMemoryP->getLabel() == "DRAM 2");
    ASSERT_TRUE(myMemoryP->size == 128);
    ASSERT_TRUE(myMemoryP->access_time == 4);
    ASSERT_TRUE(myMemoryP->source == "Auxiliary bus");

    // Get third component - My bus 1
    Bus *myBusP =  dynamic_cast<Bus*>(myPlatform.components[2]);
    
    // Assert values of My bus 1
    ASSERT_TRUE(myBusP->getLabel() == "My bus 1");
    ASSERT_TRUE(myBusP->width == 3);
    ASSERT_TRUE(myBusP->source == "Main processing unit");

    // Get fourth component - Auxiliary bus
    myBusP =  dynamic_cast<Bus*>(myPlatform.components[3]);
    
    // Assert values of Auxiliary bus
    ASSERT_TRUE(myBusP->getLabel() == "Auxiliary bus");
    ASSERT_TRUE(myBusP->width == 2);
    ASSERT_TRUE(myBusP->source == "Coproc");

    // Get fifth component - Main processing unit
    CPU *myCPUP =  dynamic_cast<CPU*>(myPlatform.components[4]);
    
    // Assert values of Main processing unit -- TODO: Check if program is correctly loaded
    ASSERT_TRUE(myCPUP->getLabel() == "Main processing unit");
    ASSERT_TRUE(myCPUP->cores == 4);
    ASSERT_TRUE(myCPUP->frequency == 5);

    // Get sixth component - Main processing unit
    myCPUP =  dynamic_cast<CPU*>(myPlatform.components[5]);
    
    // Assert values of Main processing unit -- TODO: Check if program is correctly loaded
    ASSERT_TRUE(myCPUP->getLabel() == "Coproc");
    ASSERT_TRUE(myCPUP->cores == 2);
    ASSERT_TRUE(myCPUP->frequency == 2);

    // Get seventh component - Display
    Display *myDisplayP =  dynamic_cast<Display*>(myPlatform.components[6]);
    
    // Assert values of Main processing unit -- TODO: Check if program is correctly loaded
    ASSERT_TRUE(myDisplayP->refresh_rate == 8);
    ASSERT_TRUE(myDisplayP->source == "DRAM 2");
}

// Runs all TEST functions declared at this file
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
