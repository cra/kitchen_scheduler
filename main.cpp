#include <iostream>
#include <exception>

#include "InputParser.hpp"

int main(int argc, char **argv)
{
    argc--; argv++;

    // open input file based on argv.
    try {
        InputParser input(argv[1]);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        InputParser input("/some/default/input");
    }
    // init parser.
    // read db for people.

    std::cout << "Plz lower your expectations." << std::endl;

}

