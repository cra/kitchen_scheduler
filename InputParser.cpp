#include "InputParser.hpp"


// Прочитать входной файл. Заполняется массив пользователей и график дежурств.
InputParser::InputParser(const std::string& filename):
    filename(filename) 
{
    std::cout << boost::format("[InputParser] Input file: %s\n") % filename;

    std::ifstream input(filename.c_str());
    std::string s, firstWord;
    while(std::getline(input, s)) {
        // skip comments
        if (s[0] == '#') {
            continue;
        }

        boost::tokenizer<> toker(s);
        boost::tokenizer<>::iterator t = toker.begin();

        firstWord = (std::string)(*t);


        if (firstWord == "person") {
            t++;
            std::string name = *t; 
            t++;
            std::string surname = *t;
            t++;
            bool male = ((std::string)(*t) == "male");
            DutyManager::addDutyPerson(name, surname, male);
        } 
        else if (firstWord == "event") {
            t++;
            std::string name = *t; 
            t++;
            int f_req = boost::lexical_cast<int>(*t);
            t++;
            int m_req = boost::lexical_cast<int>(*t);
            DutyManager::addDutyEvent(name, f_req, m_req);
        }
        else {
            std::cout << "[InputParser] Cannot parse config line: " << s;
        }

    }
}
