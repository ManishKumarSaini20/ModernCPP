#pragma once
#include<iostream>
#include<string>
#include<vector>
namespace EmployeeNamespace
{
class Employee
{
    int m_ID;
    std::string m_empName;
    std::vector<Employee> m_empList;
    public:
    explicit Employee(int id = 0, const std::string& name = "") noexcept;

    ~Employee() noexcept;

    void addEmployee(const int& id, const std::string& name);
    void RemoveEmployee(const int& id);
    void DisplayEmployee() const noexcept;
};
}
