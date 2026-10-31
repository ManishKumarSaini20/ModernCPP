#include "Header/Employee.h"

int main()
{
    EmployeeNamespace::Employee emp;
    emp.addEmployee(1, "John Doe");
    emp.addEmployee(2, "Jane Smith");
    emp.DisplayEmployee();
    emp.RemoveEmployee(1);
    emp.DisplayEmployee();
    return 0;
}