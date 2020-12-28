
#include <iostream>
#include <map>
#include <vector>
#include <string>


#include <Employee.h>
#include <HRMS.h>


double pensjaMinimalna = 1.0f;


int main(int argc, char *argv[]){

    HRMS enis;
    
{
    Employee e1("001","imie1","nazw1","dep1","pos1");
    Employee e2("002","imie2","nazw2","dep2","pos2");
    Employee e3("003","imie3","nazw3","dep3","pos3");
    Employee e4("004","imie4","nazw4","dep4","pos3");
    Employee e5("005","imie5","nazw5","dep4","pos3");
    Employee e6("006","imie6","nazw6","dep3","pos3");
    Employee e7("007","imie7","nazw7","dep1","pos3");
    Employee e8("008","imie8","nazw8","dep2","pos3");
    Employee e9("009","imie9","nazw9","dep3","pos3");
    Employee e10("010","imie10","nazw10","dep3","pos3");

    enis.add(e2,e2.department,2001.0f);
    enis.add(e1,e1.department,2002.50f);
    enis.add(e3,e3.department,2000.52f);    
    enis.add(e4,e4.department,112.f);    
    enis.add(e5,e5.department,21000.52f);    
    enis.add(e6,e6.department,12000.52f);    
    enis.add(e7,e7.department,33000.60f);    
    enis.add(e8,e8.department,42000.90f);    
    enis.add(e9,e9.department,199999.99f);    
    enis.add(e10,e10.department,420.69f);    

}
   

    try
    {
        Employee E("001","zaDlugieImie12345","nazw9","dep3","pos3");

        try
        {    enis.add(E,E.department,300.5f);   
        }
        catch(const std::exception& e)
        {    std::cerr << e.what() << '\n';     
        } 
    }
    catch(const std::runtime_error& ex)    
    {   std::cout << ex.what() << std::endl;    
    }

    try
    {
        Employee E("001","janek","bogacz","dep3","pos1");
        
        try
        {    enis.add(E,E.department,100000000.5f);   
        }
        catch(const std::exception& e)
        {    std::cerr << e.what() << '\n';     
        } 
    }
    catch(const std::runtime_error& ex)    
    {   std::cout << ex.what() << std::endl;    
    }
    




    
    enis.printDepartment("dep1");
    enis.printDepartment("dep2");
    enis.printDepartment("dep3");

    enis.printSalaries();    
    enis.printSalariesSorted();

    enis.changeSalary("009", 33300.50f);
    enis.printSalariesSorted();


    return 0;
};