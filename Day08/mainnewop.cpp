#include<iostream>
#include<vector>
#include<algorithm>

template<typename T>
using myvect = std::vector<T>;

template<typename T>
void printvect(myvect<T>& v)
{
    for(const auto& elem : v)
    {
        std::cout<<"elem = "<<elem<<'\n';
    }
}

int main()
{
    myvect<int> v1{1,2,3,4,5};
    myvect<int> v2(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(),[](const int& i){return i*2;});
    std::cout<<"print v1.\n";
    printvect(v1);
    std::cout<<"print v2.\n";
    printvect(v2);

    bool flag = std::all_of(v2.begin(), v2.end(), [](const int& i){return i % 2 == 0;});
    if(flag != false)
    {
        std::cout<<"All are even.\n";
    }
    else
    {
        std::cout<<"all are odd.\n";
    }

    bool flag2 = std::none_of(v2.begin(), v2.end(),[](const int& i){return i % 2 == 1;});
    if(flag2 != false)
    {
        std::cout<<"All are odd.\n";
    }
    else
    {
        std::cout<<"all are even.\n";
    }

    bool flag3 = std::any_of(v2.begin(), v2.end(), [](const int& i){return i % 2 == 0;});
    if(flag3 != false)
    {
        std::cout<<"at least 1 is even.\n";
    }
    else
    {
        std::cout<<"all are odd.\n";
    }

    bool flag4 = std::any_of(v2.begin(), v2.end(),[](const int& i){return i % 2 == 1;});
    if(flag4 != false)
    {
        std::cout<<"at least 1 is odd.\n";
    }
    else
    {
        std::cout<<"all are even.\n";
    }
    return 0;
}