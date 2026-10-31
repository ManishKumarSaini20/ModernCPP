#include<iostream>
#include<vector>
#include<algorithm>
template<typename T>
using Vect = std::vector<T>;

template<typename T>
void printVect(Vect<T>& v)
{
    for(const auto& val : v)
    {
        std::cout<<"val = "<<val<<'\n';
    }
}

int main()
{
    int y = 20;
    auto func = [&y](const int& x) -> void {std::cout<<"Print x+y = "<<x+y<<'\n';};
    int x = 10;
    func(x);
    Vect<int> v1;
    Vect<int> v2;
    auto byval = [v1,v2](const int& a) mutable -> void
    {
        v1.push_back(a);
        v2.push_back(a);
    };

    auto byrf = [&v1,&v2](const int& a) -> void
    {
        v1.push_back(a);
        v2.push_back(a);
    };

    auto bymix = [v1,&v2](const int& a) mutable -> void
    {
        v1.push_back(a);
        v2.push_back(a);
    };

    int a = 10;
    int b = 20;
    int c = 30;
    byval(a);
    byrf(b);
    bymix(c);

    std::cout<<"print v1 \n";
    printVect(v1);
    std::cout<<"print v2 \n";
    printVect(v2);

    Vect<int> v3{1,2,3,4,5};
    std::cout<<"print v3.\n";
    printVect(v3);
    std::for_each(v3.begin(), v3.end(), [](int& val) -> int {return val += 5;});
    std::cout<<"print v3 after for_each.\n";
    printVect(v3);
    Vect<int>::iterator it = std::find_if(v3.begin(), v3.end(),[](const int& a) -> bool {return a == 11;});
    if(it != v3.end())
    {
        std::cout<<"*it = "<<*it<<std::endl;
    }
    else
    {
        std::cout<<"Couldn't find 11 in v3.\n";
    }

    v3.insert(v3.end(),8);
    v3.insert(v3.end(),8);
    v3.insert(v3.end(),8);
    int count = std::count_if(v3.begin(), v3.end(),[](const int& a){return a == 8;});
    std::cout<<"count = "<<count<<'\n';

    std::cout<<"v3 before sort .\n";
    printVect(v3);
    std::sort(v3.begin(), v3.end(),[](const int& a, const int& b) -> bool {return a > b;});
    std::cout<<"v3 after sort .\n";
    printVect(v3);

    Vect<int>::iterator it1 = std::find_if(v3.begin(), v3.end(),[](const int& a) -> bool {return a%2 == 0;});
    if(it1 != v3.end())
    {
        std::cout<<"first even *it1 = "<<*it1<<std::endl;
    }
    else
    {
        std::cout<<"Couldn't find 11 in v3.\n";
    }

    int icountodd = 0;
    for(Vect<int>::iterator it2 = v3.begin(); it2 != v3.end(); ++it2)
    {
        if((*it2)%2 ==1)
        {
            ++icountodd;
        }
    }
    std::cout<<"odd number count = "<<icountodd<<'\n';

    int icountoddl = std::count_if(v3.begin(), v3.end(), [](const int& a){return a % 2 == 1;});
    std::cout<<"odd number count = "<<icountoddl<<'\n';
    return 0;
}