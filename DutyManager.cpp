#include "DutyManager.hpp"

DutyManager* DutyManager::instance = NULL;

DutyManager::DutyPerson::DutyPerson(const std::string& name, const std::string& surname):
    Name(name), Surname(surname) 
{
    std::cout << boost::format("[DutyPerson] Дежурный %s добавлен.\n") % getFullName();
}

DutyManager* DutyManager::getInstance()
{
    if(instance == NULL)
        instance = new DutyManager();
    return instance;
}

void DutyManager::addDutyPerson(boost::shared_ptr<DutyPerson> p)
{
    people.push_back(p);
}

void DutyManager::addDutyPerson(const std::string& Name, const std::string& Surname)
{
    boost::shared_ptr<DutyPerson> p(new DutyPerson(Name, Surname));
    DutyManager::getInstance()->addDutyPerson(p);
}
