#include "InputParser.hpp"

#include <iostream>
#include <boost/tokenizer.hpp>
#include <string>
#include <fstream>

InputParser::InputParser(const std::string& filename):
    filename(filename) 
{
    std::ifstream input(filename.c_str());
    std::string s;
    while(std::getline(input, s)) {
        boost::tokenizer<> toker(s);
        for(boost::tokenizer<>::iterator beg = toker.begin(); beg != toker.end(); ++beg) 
        {
            std::cout << *beg << '\n' ;
    }
    std::cout << filename << std::endl;
}
