#include "InputParser.hpp"


// Прочитать входной файл. Заполняется массив пользователей и график дежурств.
InputParser::InputParser(const std::string& filename):
    filename(filename) 
{
    std::cout << boost::format("[InputParser] Input file: %s\n") % filename;

    std::ifstream input(filename.c_str());
    std::string s;
    while(std::getline(input, s)) {
        boost::tokenizer<> toker(s);
        boost::tokenizer<>::iterator t = toker.begin();
        DutyManager::addDutyPerson(*t, *(t++));
    }
}
