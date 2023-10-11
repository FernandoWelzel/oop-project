CXX = g++

# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

TARGET = main

SOURCE = source/main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CFLAGS) -o $(TARGET) $(SOURCE)

clean:
	rm $(TARGET)