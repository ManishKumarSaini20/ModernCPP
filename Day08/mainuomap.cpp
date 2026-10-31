#include<iostream>
#include<unordered_map>

template<typename T1, typename T2>
using mymap = std::unordered_map<T1, T2>;

int main()
{
    mymap<int, std::string> map1;
    map1[3] = "aa";
    map1[1] = "bb";
    map1[5] = "cc";
    map1[4] = "dd";
    map1[2] = "ee";
    map1[6] = "aa";
    map1[7] = "aa";

    for(const std::pair<int, std::string> elem : map1)
    {
        std::cout<<"elem.first = "<<elem.first<<" elem.second = "<<elem.second<<'\n';
    }
    map1.insert(std::make_pair(9,"gg"));
    map1.insert(std::make_pair(8,"hh"));

    mymap<int, std::string>::iterator it = map1.find(8);
    if(it != map1.end())
    {
        std::cout<<"it->first = "<<it->first<<" it->second = "<<it->second<<'\n';
    }
    else
    {
        std::cout<<"We couldn't find the required key in the mapa.\n";
    }
    std::cout<<"map1.size() = "<<map1.size()<<std::endl;
    map1.erase(3);
    std::cout<<"After erase map1.size() = "<<map1.size()<<std::endl;
    //map1.erase(map1.begin()+5);
    //map1.erase(map1.end()-2);
    for(const std::pair<int, std::string> elem : map1)
    {
        std::cout<<"elem.first = "<<elem.first<<" elem.second = "<<elem.second<<'\n';
    }
    if(map1.empty() == false)
    {
        std::cout<<"There are elements in map.\n";
    }
    else
    {
        std::cout<<"map is empty.\n";
    }
    return 0;
}