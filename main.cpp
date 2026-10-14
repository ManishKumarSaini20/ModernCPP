#include<iostream>
#include<vector>
#include<string>

template<typename T>
using Vect = std::vector<T>;

template<typename T>
void PrintVect(const Vect<T>& vect)
{
    for(const auto& val : vect)
    {
        std::cout<<val<<" ";
    }
    std::cout<<'\n';
}

enum class Color
{
    RED,
    GREEN,
    YELLOW
};

enum VehicleEnum
{
    CAR,
    BUS,
    TRUCK
};

enum class VehicleEnum1
{
    CAR,
    BUS,
    TRUCK
};

int main()
{
    std::cout<<"Hello Manish\n";
    Vect<int> VectInt{1,2,3,4,5};
    Vect<std::string> VectStr{"Manish", "Kumar", "Singh"};
    PrintVect(VectInt);
    PrintVect(VectStr);
    std::cout<<"Color::RED = "<<static_cast<int>(Color::RED)<<'\n';
    std::cout<<"Color::GREEN = "<<static_cast<int>(Color::GREEN)<<'\n';
    std::cout<<"Color::YELLOW = "<<static_cast<int >(Color::YELLOW)<<'\n';
    std::cout<<"VehicleEnum::CAR = "<<CAR<<'\n';
    std::cout<<"VehicleEnum::BUS = "<<BUS<<'\n';
    std::cout<<"VehicleEnum::TRUCK = "<<TRUCK<<'\n';
    return 0;
}