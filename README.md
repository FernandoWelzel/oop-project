# oop-project

This is the final project for the course of Object-Oriented Programming in C++.

Objective: make a HW Platform Simulator.

![alt text](docs/Subject-HW_Simulator.png)

## Compiling

This project uses Cmake to automate the build and compilation process. To compile the project, is prefered to create a $build$ folder so that the Make enviromment is organized. In the folder run the command `cmake` followed by the path to the CMakeLists.txt file. A Makefile will be created, allowing to compile the project by a simple `make` command. The following code shows how to compile the base implementation.

```sh
mkdir build
cd build
cmake ..
make
```


## Running

The executable recieves one parameter, this being the path to the platform configuration file. A reference implementation can be found in the `data` folder of this repository. The following example shows how to run the base implementation:

```sh
./build/main ./data/platform.txt
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
