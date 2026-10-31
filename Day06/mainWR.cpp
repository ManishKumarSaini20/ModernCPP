#include<iostream>
#include<thread>
#include<mutex>
#include<shared_mutex>

int sharedData = 100;
std::shared_mutex smtx;


void reader()
{
    std::shared_lock<std::shared_mutex> lock(smtx);
    std::cout<<"reader is reading the data = "<<sharedData<<std::endl;
}

void writer()
{
    std::unique_lock<std::shared_mutex> lock(smtx);
    ++sharedData;
    std::cout<<"writer is writing the data = "<<sharedData<<std::endl;   
}

int main()
{
    std::thread T1(reader);
    std::thread T2(reader);
    std::thread T3(writer);
    std::thread T4(reader);
    std::thread T5(reader);

    T1.join();
    T2.join();
    T3.join();
    T4.join();
    T5.join();
    return 0;
}