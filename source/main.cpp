#include <iostream>

#include <main.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    Platform myPlataform("./data/plataform.txt");

    myPlataform.build();

    myPlataform.simulate();
    
    return 0;
}
