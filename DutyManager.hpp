#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <boost/noncopyable.hpp>
#include <boost/format.hpp>


// хранение дежурных и доступ к ним. Singleton
class DutyManager : private boost::noncopyable {

    // человек-дежурный
    class DutyPerson {
        private:
            const std::string Name;
            const std::string Surname;

        public:
            DutyPerson(const std::string& name, const std::string& surname);
            ~DutyPerson() {};
            const std::string getFullName() {return boost::str(boost::format("%1% %2%") % Name.c_str() % Surname.c_str());}
    };

    private:
        std::vector<boost::shared_ptr<DutyPerson> > people;
        DutyManager() {};
        static DutyManager* instance;
        static DutyManager* getInstance();
        void addDutyPerson(boost::shared_ptr<DutyPerson> person);
    public:
        static void addDutyPerson(const std::string &Name, const std::string &Surname);
};
