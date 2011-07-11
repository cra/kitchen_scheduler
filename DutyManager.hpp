#pragma once
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <boost/noncopyable.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/format.hpp>


// хранение дежурных и доступ к ним. Singleton
class DutyManager : private boost::noncopyable {

    // человек-дежурный
    class DutyPerson {
        private:
            const std::string Name;
            const std::string Surname;
            const bool male;

        public:
            DutyPerson(const std::string& name, const std::string& surname, const bool is_male);
            ~DutyPerson() {};
            const std::string getFullName() {return boost::str(boost::format("%1% %2%") % Name.c_str() % Surname.c_str());}
            bool is_male() {return male;}
    };

    // событие, на котором нужны дежурные
    class DutyEvent {
        private:
            const std::string Name;
            const unsigned int female_wanted;
            const unsigned int male_wanted;

        public:
            DutyEvent(const std::string& name, const int female_wanted, const int male_wanted);
            ~DutyEvent() {};
    };

    private:
        std::vector<boost::shared_ptr<DutyPerson> > people;
        std::vector<boost::shared_ptr<DutyEvent> > events;
        const std::vector<boost::shared_ptr<DutyPerson> >::const_iterator current;
        DutyManager() {};
        static DutyManager* instance;
        static DutyManager* getInstance();
        void shuffle();
        boost::shared_ptr<DutyPerson> getThatGuy(int num);
        void addDutyPerson(boost::shared_ptr<DutyPerson> person);
        void addDutyEvent(boost::shared_ptr<DutyEvent> event);
    public:
        static void addDutyPerson(const std::string &Name, const std::string &Surname, const bool &is_male);
        static void addDutyEvent(const std::string &Name, const int &female_request, const int &male_request);
        static void test_schedule(int pack);
};
