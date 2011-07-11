#include "DutyManager.hpp"

DutyManager* DutyManager::instance = NULL;


// Тупо конструктор-флудилка.
DutyManager::DutyPerson::DutyPerson(const std::string& name, const std::string& surname, const bool is_male):
    Name(name), Surname(surname), male(is_male)
{
    std::cout << boost::format("[DutyPerson] Дежурный %s добавл%s.\n") % getFullName() % (male ? "ен" : "ена");
}

// Ещё один тупо конструктор-флудилка.
DutyManager::DutyEvent::DutyEvent(const std::string& name, const int female_wanted, const int male_wanted):
    Name(name), female_wanted(female_wanted), male_wanted(male_wanted)
{
    std::cout << boost::format("[DutyEvent] Событие '%s' добавлено. Требуется %s М и %s Ж.\n") % Name % male_wanted % female_wanted;
}

// синглтонные замарочки. Этот метод я хочу оставить приватным, чтобы наружу
// выставить только несколько статических методов.
DutyManager* DutyManager::getInstance()
{
    if(instance == NULL)
        instance = new DutyManager();
    return instance;
}

// внутренний метод для добавления дежурного.
void DutyManager::addDutyPerson(boost::shared_ptr<DutyPerson> p)
{
    people.push_back(p);
}

// внутренний метод для добавления события.
void DutyManager::addDutyEvent(boost::shared_ptr<DutyEvent> e)
{
    events.push_back(e);
}

// статический метод, добавляющий по имени-фамилии дежурного в общий список.
void DutyManager::addDutyPerson(const std::string& Name, const std::string& Surname, const bool &is_male)
{
    boost::shared_ptr<DutyPerson> p(new DutyPerson(Name, Surname, is_male));
    DutyManager::getInstance()->addDutyPerson(p);
}

// статический метод, добавляющий информацию о каком-то событии в общий список 
void DutyManager::addDutyEvent(const std::string& Name, const int &female_request, const int &male_request)
{
    boost::shared_ptr<DutyEvent> e(new DutyEvent(Name, female_request, male_request));
    DutyManager::getInstance()->addDutyEvent(e);
}

// перемешать список
void DutyManager::shuffle()
{
    srand(unsigned(time(NULL)));
    std::random_shuffle(people.begin(), people.end());
}

boost::shared_ptr<DutyManager::DutyPerson> DutyManager::getThatGuy(int num)
{
    return people.at(num % people.size());
}

// в пачке по pack выдать группы дежурящих.
void DutyManager::test_schedule(int pack)
{
    DutyManager::getInstance()->shuffle();

    auto g = 0;
    for(auto i = 0; i < 5*pack; ++i)
    {
        std::cout << DutyManager::getInstance()->getThatGuy(i)->getFullName();
        if(!(++g % pack))
        {
            std::cout << std::endl;
        } else {
            std::cout << " ";
        }
    }
    std::cout <<  std::endl;

}

