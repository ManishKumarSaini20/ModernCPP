#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>

std::mutex mtx;
std::condition_variable cv;

std::queue<int> q;

bool production_complete = false;

void producer()
{
    for(int i = 1; i <= 5; ++i)
    {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(i);
        std::cout<< "Produced : "<< i<< '\n';
    }
    {
        std::lock_guard<std::mutex> lock(mtx);
        production_complete = true;
    }
    cv.notify_one();
}

void consumer()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []()
        {
            return !q.empty() || production_complete;
        });
        if(q.empty())
        {
            break;
        }

        int data = q.front();
        q.pop();

        std::cout<< "Consumed : "<< data<< '\n';
    }
}

int main()
{
    std::thread T1(producer);
    std::thread T2(consumer);

    T1.join();
    T2.join();

    return 0;
}