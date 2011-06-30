#pragma once

#include <string>
#include <vector>

#include "DutyPerson.hpp"

class InputParser {
    // Обработчик входных файлов с данными по людям и их использованию (график
    // их присутствия, на что их можно ставить, что они лучше всего делают,
    // на что нельзя, какие коментарии, и так далее.
    // Без имени файла бессмысленен, поэтому пустой конструктор запрещён.
    private:
        const std::string filename;
        std::vector<DutyPerson> people;
        InputParser();
        InputParser(const InputParser& forbidden);

    public:
        InputParser(const std::string& filename);
        ~InputParser() {};

};

