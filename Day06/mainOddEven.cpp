#include<iostream>
#include<mutex>
#include<condition_variable>
#include<thread>

std::mutex mtx;
std::condition_variable cv;
int num = 1;
int MAX = 10;

void printOdd()
{
    while(num <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]()
    {
        return num % 2 == 1;
    });
    if(num > MAX)
    {
        break;
    }
    std::cout<<"odd = "<<num<<std::endl;
    ++num;
    cv.notify_one();
    }
}

void printEven()
{
    while(num <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock,[]()
    {
        return num % 2 == 0;
    });
    if(num > MAX)
    {
        break;
    }
    std::cout<<"odd = "<<num<<std::endl;
    ++num;
    cv.notify_one();
    }
}

int main()
{
    std::thread T1(printEven);
    std::thread T2(printOdd);
    T1.join();
    T2.join();
    return 0;
}