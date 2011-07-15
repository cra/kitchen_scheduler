#include <iostream>
#include <exception>
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>

#include "InputParser.hpp"
#include "DutyManager.hpp"

namespace po = boost::program_options;

// TODO logging system на boost::format и с контролем уровня вывода

int main(int argc, char **argv)
{
    std::string config_fname;
    int pack; 

    po::options_description desc("Options");
    desc.add_options()
        ("input,i",
         po::value<std::string>(&config_fname)->default_value("./INPUT.sample"),
         "Input file to parse with events and persons")
        ("help,h",
         "Produce help message")
        ("pack,n",
         po::value<int>(&pack)->default_value(4));

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 1;
    }

    boost::filesystem::path config(config_fname);
    if (!boost::filesystem::exists(config)) {
        std::cout << "Could not find config file " << config << std::endl; 
        return -1;
    }

    InputParser input(config_fname);

    std::cout << "Plz lower your expectations." << std::endl;

    DutyManager::test_schedule(pack);

    return 0;
}

