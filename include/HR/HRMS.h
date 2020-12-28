#ifndef HRMS_
#define HRMS_

#include <iostream>
#include <vector>
#include <map>
#include <Employee.h>
#include <iomanip>
#include <algorithm>
#include <functional>


class HRMS
{

private:
    std::vector<Employee> Employees;
    
    std::map <std::string, std::string> emp_department;
    std::map <std::string, double> emp_salary;



    std::map <std::string, std::string>::iterator it;
    
public:


    HRMS(){Employees.reserve(15);};
    
    ~HRMS(){};
    // dodająca użytkownika do systemu, do danego departamentu, mającego dane wynagrodzenie
    int add(Employee& employee, std::string departmentId, double salary);

    int changeSalary(std::string employeeId, double salary);  
    //  wypisująca wszystkich pracowników danego departamentu
    void printDepartment(std::string departmentId) ;
    //  wypisująca wynagrodzenia wszystkich pracowników, wraz z informacjami o tych pracownikach, w kolejności malejącego wynagrodzenia (sortowanie ma być wykonana z użyciem std::algorithm)
    void printSalaries();

    void printSalariesSorted();

   
    



};
#endif