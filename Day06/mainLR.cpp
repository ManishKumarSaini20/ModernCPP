#include<iostream>
#include <vector>

template<typename T>
using Vect = std::vector<T>;

void Func(int& a)
{
    std::cout<<"L value.\n";
}

void Func(int&& a)
{
    std::cout<<"R value.\n";
}


class Emplyoee
{
    public:
    explicit Emplyoee() noexcept
    {
        std::cout<<"Emplyoee::Emplyoee.\n";
    }

    Emplyoee(const Emplyoee&)
    {
        std::cout<<"Emplyoee copy constructor.\n";
    }

    Emplyoee(Emplyoee&&) noexcept
    {
        std::cout<<"Emplyoee move copy constructor.\n";
    }

    ~Emplyoee()
    {
        std::cout<<"Emplyoee Destructor.\n";
    }

    Emplyoee& operator = (const Emplyoee& )
    {
        std::cout<<"Emplyoee assignment operator.\n";
        return *this;
    }

    Emplyoee& operator = (Emplyoee&&)
    {
        std::cout<<"Emplyoee move assignment operator.\n";
        return *this;
    }
};

class CManish
{
    char* ptr;
};

int main()
{
    int x = 10;
    int l = 20;
    int& y = x;
    //int& z = 10;
    int& m = l;
    const int& n = x + l;
    Func(x);
    Func(x+y);

    int a = 100;
    std::cout<<"a = "<<a<<std::endl;
    int b = std::move(a);
    std::cout<<"a = "<<a<<std::endl;
    std::cout<<"b = "<<b<<std::endl;

    Emplyoee e1;
    Emplyoee e2 = e1;
    Emplyoee e3 = std::move(e2);
    std::cout<<"vector part started.\n";
    Vect<Emplyoee> v1;
    v1.push_back(Emplyoee());
    v1.push_back(Emplyoee());
    v1.push_back(Emplyoee());
    v1.push_back(Emplyoee());
    std::cout<<"vector part ended.\n";
    return 0;
}