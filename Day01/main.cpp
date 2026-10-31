#include <iostream>
#include <typeinfo>
#include <string>
#include <memory>
#include <vector>

void func(int a)
{
    std::cout << "int\n";
}

void func(int* ptr)
{
    std::cout << "pointer\n";
}



int main()
{
    auto value = 100;
    std::cout<<"value = "<<value<<std::endl;
    std::cout<<"Type of value = "<<typeid(value).name()<<std::endl;

    int * ptr = nullptr;
    if(ptr == nullptr)
    {
        std::cout<<"ptr is nullptr"<<std::endl;
    }

    //func(NULL);
    func(nullptr); // C++11 and later, nullptr is preferred over NULL
    std::cout<<"Type of nullptr = "<<typeid(nullptr).name()<<std::endl;
    std::cout<<"Type of NULL = "<<typeid(NULL).name()<<std::endl;
    auto str = std::string("Hello");
    std::cout<<"Type of str = "<<typeid(str).name()<<std::endl;

    int * ptr1 = nullptr;
    ptr = new int(100);
    std::cout<<"*ptr = "<<*ptr<<std::endl;
    delete ptr;
    ptr = nullptr;
    std::unique_ptr<int> ptr2(new int(200));
    std::cout<<"ptr2 = "<<ptr2.get()<<std::endl;
    std::cout<<"*ptr2 = "<<*ptr2<<std::endl;
    ptr2.reset();
    ptr2 = nullptr;
    std::vector<int> Vect {1,2,3,4,5,6,7,8,9,10};

    std::cout<<"Vect before erase: "; 
    for(const auto & val : Vect)
    {
        std::cout<<val<<" ";
    }

    for(std::vector<int>::iterator it = Vect.begin(); it != Vect.end(); ++it)
    {
        if(*it ==5)
        {
            Vect.erase(it);
        }
    }
    
    std::cout<<"\nVect after erase: "; 
    for(const auto & val : Vect)
    {
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    return 0;
}