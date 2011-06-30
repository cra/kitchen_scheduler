#include <iostream>
#include <exception>

#include "InputParser.hpp"
#include "DutyManager.hpp"

// TODO logging system на boost::format и с контролем уровня вывода

int main(int argc, char **argv)
{
    argc--; argv++;

    // open input file based on argv.
    // TODO boost::program_options
    try {
        InputParser input(argv[0]);
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
        InputParser input("/some/default/input");
    }

    std::cout << "Plz lower your expectations." << std::endl;

    DutyManager::test_schedule(4);


}

