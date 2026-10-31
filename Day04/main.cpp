#include <iostream>
#include <vector>

template<typename T>
using Vect = std::vector<T>;

int main()
{
    Vect<int> vect {10,20,30,40,50};
    std::cout<<"using normal iterator"<<'\n';       
    for(Vect<int>::iterator it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout<<*it<<'\n';
    }
    std::cout<<"using auto iterator"<<'\n';
    for(auto it = vect.begin(); it != vect.end(); ++it)
    {
        std::cout<<*it<<'\n';
    }
    std::cout<<"using range-based for loop"<<'\n';
    for(const auto& val :vect)
    {
        std::cout<<val<<'\n';
    }

    std::cout<<"using const iterator"<<'\n';
    for(Vect<int>::const_iterator it = vect.cbegin(); it != vect.cend(); ++it)
    {
        std::cout<<*it<<'\n';
        //*it = 100; // This line will cause a compilation error because we cannot modify the value through a const_iterator
    }
    std::cout<<"vect.front() = "<<vect.front()<<'\n';
    std::cout<<"vect.back() = "<<vect.back()<<'\n';
    std::cout<<"vect.size() = "<<vect.size()<<" vect.capacity() = "<<vect.capacity()<<'\n';
    vect.insert(vect.begin() + 2, 100);
    std::cout<<"vect after inserting 100 at index 3"<<'\n';
    for(const auto& val :vect)
    {
        std::cout<<val<<'\n';
    }
    std::cout<<"vect.size() = "<<vect.size()<<" vect.capacity() = "<<vect.capacity()<<'\n';
    vect.erase(vect.begin() + 2);
    std::cout<<"vect after erasing element at index 3"<<'\n';
    for(const auto& val :vect)
    {
        std::cout<<val<<'\n';
    }
    std::cout<<"vect.size() = "<<vect.size()<<" vect.capacity() = "<<vect.capacity()<<'\n';
    if(vect.empty() == false)
    {
        std::cout<<"vect is not empty"<<'\n';
    }
    else
    {
        std::cout<<"vect is empty"<<'\n';
    }
    //vect.clear();
    vect.erase(vect.begin(), vect.end());
    std::cout<<"vect after clear()"<<'\n';
    std::cout<<"vect.size() = "<<vect.size()<<" vect.capacity() = "<<vect.capacity()<<'\n';
    if(vect.empty() == false)
    {
        std::cout<<"vect is not empty"<<'\n';
    }
    else
    {
        std::cout<<"vect is empty"<<'\n';
    }
    vect.push_back(999);
    std::cout<<"vect after push_back(999)"<<'\n';
    std::cout<<"vect.size() = "<<vect.size()<<" vect.capacity() = "<<vect.capacity()<<'\n';
    return 0;
}
