#include <vector>
#include<iostream>

template<typename T>
using Vect = std::vector<T>;

int main()
{
    Vect<int> vect1;
    vect1.reserve(10);
    //std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" vect1[0] = "<<vect1[0]<<'\n';
    vect1.push_back(1);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(2);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(3);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(4);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(5);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(6);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(7);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(8);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(9);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';
    vect1.push_back(10);
    std::cout<<"vect1.size() = "<<vect1.size()<<" vect1.capacity() = "<<vect1.capacity()<<" &vect1[0] = "<<&vect1[0]<<'\n';

    Vect<int> vect2;
    vect2.resize(5);
    std::cout<<"vect2.size() = "<<vect2.size()<<" vect2.capacity() = "<<vect2.capacity()<<" &vect2[0] = "<<&vect2[0]<<'\n';
    for(const auto& val : vect2)
    {
        std::cout << val <<'\n';
    }
    return 0;
}