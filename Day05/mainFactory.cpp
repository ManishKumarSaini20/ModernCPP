#include<iostream>
#include<memory>

class Vehicle
{
    public:
    Vehicle()
    {
        std::cout<<"Vehicle constructor.\n";
    }
    virtual ~Vehicle()
    {
        std::cout<<"Vehicle destructor.\n";
    }

    virtual void drive() = 0;
};

class CAR : public Vehicle
{
    public:
    void drive() override
    {
        std::cout<<"Driving a car.\n";
    }
};

class TRUCK : public Vehicle
{
    public:
    void drive() override
    {
        std::cout<<"Driving a truck.\n";
    }
};

class VehicleFactory
{
    public:
    static std::unique_ptr<Vehicle> createInstance(const std::string& type)
    {
        if(type == "CAR")
        {
            return std::make_unique<CAR>();
        }
        else if(type == "TRUCK")
        {
            return std::make_unique<TRUCK>();
        }
        else
        {
            return nullptr;
        }
    }
};

int main()
{
    auto vehicle = VehicleFactory::createInstance("CAR");
    vehicle->drive();
    return 0;
}
