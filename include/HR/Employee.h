#ifndef EMPLOYEE_
#define EMPLOYEE_

#include <iostream>

class Employee
{

private:
        
public:
    std::string id;
    std::string name;
    std::string surname;
    std::string department;
    std::string position;


    
    ~Employee(){};
    Employee(){};
    Employee(const char* , std::string , std::string , std::string , std::string );




    /* 
    Employee(const Employee& E)
        : id(E.id), name(E.name), surname(E.surname), department(E.department), position(E.position)
    {
        std::cout<<" Copped\n";
    }
    */
    


};
#endif
