#include <Employee.h>



Employee::Employee(const char* id, std::string name, std::string surname, std::string department, std::string position){
    if(name.size() > 15)    throw std::runtime_error{ "-!- zbyt dlugie imie -!-" };
    if(surname.size() > 15)    throw std::runtime_error{ "-!- zbyt dlugie nazwisko -!-" };
    if(position.size() > 15)    throw std::runtime_error{ "-!- zbyt dlugia nazwa pozycji -!-" };
    if(department.size() > 15)    throw std::runtime_error{ "-!- zbyt dlugia nazwa departamentu -!-" };
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->position = position;
    this->department = department;

};