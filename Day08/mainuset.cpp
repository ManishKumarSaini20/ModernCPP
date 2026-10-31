#include<iostream>
#include<unordered_set>

template<typename T>
using myset = std::unordered_set<T>;

int main()
{
    myset<int> s1;
    s1.insert(3);
    s1.insert(1);
    s1.insert(5);
    s1.insert(2);
    s1.insert(4);
    s1.insert(4);
    s1.insert(4);
    for(const int& val : s1)
    {
        std::cout<<"val = "<<val<<'\n';
    }

    myset<int>::iterator it = s1.find(3);
    if(it != s1.end())
    {
        std::cout<<"*it = "<<*it<<'\n';
    }
    else
    {
        std::cout<<"Element 3 is not found.\n";
    }
    std::cout<<"size before erase = "<<s1.size()<<'\n';
    s1.erase(3);
    std::cout<<"size before erase = "<<s1.size()<<'\n';
    for(const int& val : s1)
    {
        std::cout<<"val = "<<val<<'\n';
    }
    return 0;
}