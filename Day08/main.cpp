#include<iostream>
#include<thread>
#include<shared_mutex>
#include<mutex>
#include<chrono>

std::shared_mutex mtx;
int shared_data = 100;


void reader()
{
    std::shared_lock<std::shared_mutex> lock(mtx);
    std::cout<<"Reading shared data = "<<shared_data<<'\n';
}

void writer()
{
    std::unique_lock<std::shared_mutex> lock(mtx);
    ++shared_data;
    std::cout<<"wtiter is writting the shared_data = "<<shared_data<<'\n';
}

int main()
{
    std::thread T1(reader);
    std::thread T2(reader);
    std::thread T3(reader);
    std::thread T4(writer);
    std::thread T5(reader);
    std::thread T6(reader);
    std::thread T7(reader);
    T1.join();
    T2.join();
    T3.join();
    T4.join();
    T5.join();
    T6.join();
    T7.join();
    return 0;
}