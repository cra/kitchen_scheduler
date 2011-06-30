#include <string>
#include <iostream>
#include <boost/format.hpp>

class DutyPerson {
    private:
        const std::string Name;
        const std::string Surname;

    public:
        DutyPerson(const std::string& name, const std::string& surname);
        ~DutyPerson() {};
        const std::string getFullName() {return boost::str(boost::format("%2% %1%") % Name.c_str() % Surname.c_str());}
};
