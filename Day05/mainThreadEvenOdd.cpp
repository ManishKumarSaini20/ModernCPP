#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

std::mutex mtx;
std::condition_variable cv;
int num = 1;
const int MAX = 10;

std::mutex mtx1;
std::condition_variable cv1;
bool data_produced = false;

void producer()
{
    std::lock_guard<std::mutex> lock(mtx1);
    std::cout<<"Dtaa produced.\n";
    data_produced = true;
    cv1.notify_one();
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx1);
    cv1.wait(lock, [](){return data_produced;});
    std::cout<<"Data consumed.\n";
}

void printOdd()
{
    while(num <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
        {
            return num % 2 == 1;
        });
        if(num > MAX)
        {
            break;
        }
        std::cout<<"odd number = "<<num<<std::endl;
        ++num;
        cv.notify_one();
    }
}

void printEven()
{
    while(num <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
        {
            return num % 2 == 0;
        });
        if(num > MAX)
        {
            break;
        }
        std::cout<<"even number = "<<num<<std::endl;
        ++num;
        cv.notify_one();
    }
}

int main()
{
    std::thread T1(printOdd);
    std::thread T2(printEven);
    T1.join();
    T2.join();

    std::thread T3(consumer);
    std::thread T4(producer);
    T3.join();
    T4.join();
    return 0;
}