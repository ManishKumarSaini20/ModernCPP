#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

std::atomic<int> atcounter(0);
int icounter = 0;
std::mutex mtx;
void increment()
{
    std::lock_guard<std::mutex> lock(mtx);
    for(int i = 0; i < 100000; ++i)
    {
        ++icounter;
    }
}

void incrementatomic()
{
    for(int i = 0; i < 100000; ++i)
    {
        atcounter.fetch_add(1);
    }
}

int main()
{
    std::thread T1(increment);
    std::thread T2(increment);
    T1.join();
    T2.join();
    std::cout<<"icounter = "<<icounter<<std::endl;
    std::thread T3(incrementatomic);
    std::thread T4(incrementatomic);
    T3.join();
    T4.join();
    std::cout<<"atcounter = "<<atcounter.load()<<std::endl;
    return 0;
}