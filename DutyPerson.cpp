#include "DutyPerson.hpp"

DutyPerson::DutyPerson(const std::string& name, const std::string& surname):
    Name(name), Surname(surname) 
{
    std::cout << boost::format("[DutyPerson] Дежурный %s добавлен.\n") % getFullName();
}
