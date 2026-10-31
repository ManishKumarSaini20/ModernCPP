#include "../Header/Employee.h"

EmployeeNamespace::Employee::Employee(int id, const std::string& name) noexcept : m_ID(id), m_empName(name)
{
    std::cout<<"Employee Constructor called for "<<m_empName<<std::endl;
}

EmployeeNamespace::Employee::~Employee() noexcept
{
    std::cout<<"Employee Destructor called for "<<m_empName<<std::endl;
}

void EmployeeNamespace::Employee::addEmployee(const int& id, const std::string& name)
{
    //Employee emp;
    //emp.m_ID = id;
    //emp.m_empName = name;
    //m_empList.emplace_back(emp);
    m_empList.emplace_back(id, name);
    std::cout<<"Employee added with ID: "<<id<<" and Name: "<<name<<std::endl;
}

void EmployeeNamespace::Employee::RemoveEmployee(const int& id)
{
    if(m_empList.empty() == false)
    {
        for(std::vector<Employee>::iterator it = m_empList.begin(); it != m_empList.end(); ++it)
        {
            if(it->m_ID == id)
            {
                m_empList.erase(it);
                std::cout<<"Employee with ID: "<<id<<" removed successfully."<<std::endl;
                return;
            }
        }
    }
    else
    {
        std::cout<<"Employee list is empty. No employee to remove."<<std::endl;
    }
}


void EmployeeNamespace::Employee::DisplayEmployee() const noexcept
{
    if(m_empList.empty() == false)
    {
        for(const auto& emp : m_empList)
        {
            std::cout<<"Employee ID: "<<emp.m_ID<<", Name: "<<emp.m_empName<<std::endl;
        }
    }
}



