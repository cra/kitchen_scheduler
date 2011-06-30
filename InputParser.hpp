#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <boost/tokenizer.hpp>
#include <boost/format.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

#include "DutyManager.hpp"

class InputParser : private boost::noncopyable {
    // Обработчик входных файлов с данными по людям и их использованию (график
    // их присутствия, на что их можно ставить, что они лучше всего делают,
    // на что нельзя, какие коментарии, и так далее.
    // Без имени файла бессмысленен, поэтому пустой конструктор запрещён.
    private:
        const std::string filename;
        InputParser();

    public:
        InputParser(const std::string& filename);
        ~InputParser() {};

};

