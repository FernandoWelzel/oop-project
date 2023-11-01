add_library(sourceLibrary
    platform.cpp
    parse.cpp
    cpu.cpp
    component.cpp
    memory.cpp
    display.cpp
    bus.cpp
    queue.cpp
)

target_include_directories(sourceLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
