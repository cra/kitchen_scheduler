#include "InputParser.hpp"


InputParser::InputParser(const std::string& filename):
    filename(filename) 
{
    std::cout << boost::format("[InputParser] Input file: %s\n") % filename;

    std::ifstream input(filename.c_str());
    std::string s;
    while(std::getline(input, s)) {
        boost::tokenizer<> toker(s);
        boost::tokenizer<>::iterator t = toker.begin();
        boost::shared_ptr<DutyPerson> p(new DutyPerson(*t, *(++t)));
        people.push_back(p);
    }
}
