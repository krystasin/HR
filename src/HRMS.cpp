#include <HRMS.h>

std::ostream &operator<<(std::ostream &stream, const Employee &emp)
{

    std::cout << "|" << std::setw(8) << emp.id
              << "|" << std::setw(15) << emp.name
              << "|" << std::setw(15) << emp.surname
              << "|" << std::setw(15) << emp.department
              << "|" << std::setw(15) << emp.position;
    return stream;
}

bool cmp(std::pair<std::string, double>& a, std::pair<std::string, double>& b)
{
    return a.second > b.second;
}



int HRMS::add(Employee& employee, std::string departmentId, double salary)
{   
    if( emp_department.find(employee.id) != emp_department.end())
        throw std::runtime_error{"-!- istnieje juz pracownik o id: " + employee.id +" -!-"};
    employee.department = departmentId;     //
    Employees.emplace_back(employee);
    emp_department[employee.id] = departmentId;
    emp_salary[employee.id] = salary;

    return 0;
};

void HRMS::printDepartment(const std::string dep)
{
    {
        std::cout << "|" << "Department "<< std::setfill(' ') << std::setw(10) << dep << std::setfill('_') << std::setw(37)<<"|\n" <<std::setfill(' ')
            << "|" << std::setw(8) << "id"
            << "|" << std::setw(15) << "name"
            << "|" << std::setw(15) << "surname"
            << "|" << std::setw(15) << "position"
            << "|" << "\n|--------|---------------|---------------|---------------|\n";
    }

//    for (auto &map : emp_department)
 //       if (map.second == dep)
//            std::cout << "  " << map.first << "\n";

    for (auto &E : Employees)
        if(E.department == dep)
            std::cout             
                << "|" << std::setw(8) << E.id
                << "|" << std::setw(15) << E.name
                << "|" << std::setw(15) << E.surname
                << "|" << std::setw(15) << E.position 
                << "|\n";
    std::cout << std::endl;                
}

int HRMS::changeSalary(std::string employeeId, double salary)
{
    if (salary <= 0)  throw std::runtime_error{ "-!-nie zmieniono pensji pracownika "+ employeeId +". Zbyt niska pensja -!-" };
    emp_salary[employeeId] = salary;
    std::cout << "log: zmieniono pensje pracownika " << employeeId <<" na " << salary <<"\n";
    return 0;
}

void HRMS::printSalaries()
{
    std::cout << "|Salaries_____________________________________________________________________________|\n"
              << "|" << std::setw(8) << "id"
              << "|" << std::setw(15) << "name"
              << "|" << std::setw(15) << "surname"
              << "|" << std::setw(15) << "department"
              << "|" << std::setw(15) << "position"
              << "|" << std::setw(12) << "salary"
              << "|" << "\n|--------|---------------|---------------|---------------|---------------|------------|\n";

    for (Employee E : Employees)
    {
        std::cout << E << "|" << std::fixed << std::setprecision(2) << std::setw(12) << emp_salary[E.id] << "|\n";
    }
    std::cout << std::endl; 
}

void HRMS::printSalariesSorted(){

    std::vector<std::pair<std::string, double> > A;
    for(auto& it : emp_salary){
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);
{   //  tabelka
    std::cout << "|Salaries Sorted______________________________________________________________________|\n"
              << "|" << std::setw(8) << "id"
              << "|" << std::setw(15) << "name"
              << "|" << std::setw(15) << "surname"
              << "|" << std::setw(15) << "department"
              << "|" << std::setw(15) << "position"
              << "|" << std::setw(12) << "salary"
              << "|" << "\n|--------|---------------|---------------|---------------|---------------|------------|\n";
}

    for(auto& it : A)
    {
        for(Employee E : Employees)
            if(E.id == it.first){
                std::cout<< E << "|";
                break;
            }
        std::cout << std::fixed << std::setprecision(2) << std::setw(12)<< it.second << "|\n";   
    }
    std::cout << std::endl; 
}