#include<iostream>
#include<mutex>
#include<thread>
#include<chrono>

std::mutex mtx1;
std::mutex mtx2;

void thread1()
{
    std::lock_guard<std::mutex> lock1(mtx1);
    std::cout<<"thread1 lock1.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::lock_guard<std::mutex> lock2(mtx2);
    std::cout<<"thread1 lock2.\n";
}

void thread2()
{
    std::lock_guard<std::mutex> lock1(mtx1);
    std::cout<<"thread2 lock1.\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::lock_guard<std::mutex> lock2(mtx2);
    std::cout<<"thread2 lock2.\n";
}

// void thread1()
// {
//     std::scoped_lock lock(mtx1, mtx2);
//     std::cout<<"thread 1 is done.\n";
// }

// void thread2()
// {
//     std::scoped_lock lock(mtx1, mtx2);
//     std::cout<<"thread 2 is done.\n";
// }

int main()
{
    std::thread T1(thread1);
    std::thread T2(thread2);
    T1.join();
    T2.join();
    return 0;
}