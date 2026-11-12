#include<iostream>
#include<tuple>
#include<map>
#include<vector>
#include <variant>
#include <string_view>
#include <concepts>
#include <compare>
#include <span>
#include <array>

template<typename T1, typename T2>
using mymap = std::map<T1,T2>;

template<typename T>
using myvect = std::vector<T>;


template<typename T>
void PrintVect1(myvect<T>& v)
{
    std::cout<<"PrintVect1() called\n";
    if(std::is_integral<T>::value)
    {
        for(const auto& elem : v)
        {
            std::cout<<elem<<'\n';
        }
    }
    else
    {
        std::cout<<"T is not integral type\n";
    }
}


template<typename T>
void PrintVect(myvect<T>& v)
{
    std::cout<<"PrintVect() called\n";
    if constexpr(std::is_integral_v<T>)
    {
        for(const auto& elem : v)
        {
            std::cout<<elem<<'\n';
        }
    }
    else
    {
        std::cout<<"T is not integral type\n";
    }
}

void someFunction()
{
    std::cout<<"someFunction() called\n";
}

template<typename T>
void func(T t)
{
    if(std::is_integral<T>::value)
    {
        std::cout <<"t = "<< t<<'\n';
    }
    else
    {
        t.someFunction();   // Error for int
    }
}

template<typename T>
void func1(T t)
{
    std::cout<<"func1() called\n";
    if constexpr(std::is_integral_v<T>)
    {
        std::cout <<"t = "<< t<<'\n';
    }
    else
    {
        t.someFunction();
    }
}

union manish
{
    int i;
    char c;
    double d;
};

struct manish1
{
    double d;
    int i;
    char c;
};

template<typename ... Args>
auto sum(Args ... arg)
{
    return (... + arg);
}

void print(std::string_view str)
{
    std::cout<<str<<'\n';
}

std::string returnstr()
{
    std::string str = "Hello World";
    return str;
}

template<std::integral T>
auto addnum(T a, T b)
{
    return a+b;
}

class Person
{
    int age;
public:
    explicit Person(int iage = 0) noexcept : age(iage) {}
    auto operator<=>(const Person&) const = default;
};

void Print(std::span<int> data)
{
    for(auto v : data)
    {
        std::cout<<v<<'\n';
    }
}

// void Print1(std::array<int,5> data)
// {
//     for(auto v : data)
//     {
//         std::cout<<v<<'\n';
//     }
// }

template<typename T, std::size_t iSize>
void Print1(T (&data) [iSize])
{
    std::cout<<"Print1() called\n";
    for(auto v : data)
    {
        std::cout<<v<<'\n';
    }

    std::cout<<"Print1() called with index based loop\n";
    for(int i = 0; i < iSize; ++i)
    {
        std::cout<<data[i]<<'\n';
    }
}

int main()
{
    std::tuple<int, char, std::string> t = std::make_tuple(2,'b',"bb");
    std::pair<int , std::string> p = std::make_pair(1,"aa");
    auto [a,strname] = p;
    auto [b,c,d] = t;
    std::cout<<"a = "<<a<<" strname = "<<strname<<std::endl;
    std::cout<<"b = "<<b<<" c = "<<c<<" d = "<<d<<std::endl;
    mymap<int,std::string> m;
    m.insert(std::make_pair(3,"cc"));
    m[4] = "dd";
    for(const auto& [key,value] : m)
    {
        std::cout<<"key = "<<key<<" value = "<<value<<'\n';
    }
    myvect<int> v {1,2,3,4,5,6,7,8,9,10};
    PrintVect(v);
    PrintVect1(v);
    //func(5);
    func1(5);
    std::variant<int, std::string> var;
    var = 20;
    std::cout<<"var = "<<std::get<int>(var)<<'\n';
    if(std::holds_alternative<int>(var))
    {
        std::cout<<"var holds int\n";
    }
    else if(std::holds_alternative<std::string>(var))
    {
        std::cout<<"var holds string\n";
    }
    var = "Hello";
    std::cout<<"var = "<<std::get<std::string>(var)<<'\n';
    if(std::holds_alternative<int>(var))
    {
        std::cout<<"var holds int\n";
    }
    else if(std::holds_alternative<std::string>(var))
    {
        std::cout<<"var holds string\n";
    }
    manish union1;
    union1.i = 10;
    std::cout<<"union1.i = "<<union1.i<<'\n';
    std::cout<<"union1.c = "<<union1.c<<'\n';
    std::cout<<"union1.d = "<<union1.d<<'\n';
    union1.c = 'A';
    std::cout<<"union1.i = "<<union1.i<<'\n';
    std::cout<<"union1.c = "<<union1.c<<'\n';
    std::cout<<"union1.d = "<<union1.d<<'\n';
    union1.d = 3.14;
    std::cout<<"union1.i = "<<union1.i<<'\n';
    std::cout<<"union1.c = "<<union1.c<<'\n';
    std::cout<<"union1.d = "<<union1.d<<'\n';
    std::cout<<"sizeof(union1) = "<<sizeof(union1)<<'\n';
    std::cout<<"sizeof(manish1) = "<<sizeof(manish1)<<'\n';
    std::cout<<"sum = "<<sum(1,2,3,4,5,6,7,8,9,10)<<'\n';
    std::cout<<"sum = "<<sum(1,2,3,4,5,6,7,8)<<'\n';
    std::string s = "hello";
    print(s);
    s[2] = 'L';
    print(s);
    std::string_view sv = "KPIT";
    print(sv);
    std::cout<<"returnstr() = "<<returnstr()<<'\n';
    std::cout<<"addnum(5,10) = "<<addnum(5,10)<<'\n';

    Person p1{20};
    Person p2{30};

    if(p2 > p1)
    {
        std::cout<<"p1 younger\n";
    }
    // else if(p1 > p2)
    // {
    //     std::cout<<"p1 older\n";
    // }
    // else
    // {
    //     std::cout<<"p1 and p2 are of same age\n";
    // }
    int arr[] = {1,2,3,4,5};
    Print(arr);
    Print1(arr);
    return 0;
}