# oop-project

This is the final project for the course of Object-Oriented Programming in C++. The project focuses on building a basic hardware simulator made of CPUs, buses, memories and displays. The structure of the hardware platform is build from text files, that can be found in the `tests/data`. After building the enviroment, a program can be simulated.

## Compiling

This project uses Cmake to automate the build and compilation process. To compile the project, is prefered to create a `build` folder so that the Make enviromment is organized. In the folder run the command `cmake` followed by the path to the main `CMakeLists.txt` file. A Makefile will be created, allowing you to compile the project by a simple `make` command. The following code shows how to compile the base implementation.

```sh
mkdir build
cd build
cmake ..
make
```

## Running

To run the main executable, place yourself in the `build` folder and run the executable by the name `project`. For the moment, the executable accepts 3 options:  

- Help (-h)
- Verbose (-v): Prints extra debugging messages about each component
- Steps (-s STEPS): Determines the number of simulation steps

An example of execution, running only the first simulation step with the verbose flag, can be seen in the following code block:

```sh
cd build
./project -s -v 1 data/platform.txt
```

## Tests

This project uses the [GoogleTest](https://github.com/google/googletest) framework. There is no need to install it own your machine as it is fetched during the compilation process with Cmake. To to run the tests run the following list of commands:  

```sh
cd build
ctest
```

To run only one test at a time, go to the build/tests where you will find all the unit test binary files. An example of execution can be seen as follows:

```sh
cd build/tests
./parseTest
```

## Wishlist

- [x] Creating main executable
  - [x] Adding the verbose flag to the executable
- [x] Implementing display component
- [ ] Updating architecture
- [ ] Improve test error messages using [GoogleTest](https://github.com/google/googletest)
- [x] Improve error handling using throw
- [ ] Start using namespaces