#include<iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>
#include <queue>
#include <memory>

std::condition_variable cv;
std::condition_variable cv1;
std::mutex mtx;
std::mutex mtx1;
bool Data_ready = false;
std::shared_mutex smtx;
int shared_data = 0;
int value = 1;
int MAX = 10;
std::queue<int> Q;
std::mutex mtx2;
bool queue_ready = false;
std::condition_variable CV2;

void producer()
{
    std::lock_guard<std::mutex> lock(mtx);
    std::cout<<"Data is produced.\n";
    Data_ready = true;
    cv.notify_one();
}

void consumer()
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[](){return Data_ready;});
    std::cout<<"Data consumed.\n";
}

void reader()
{
    std::shared_lock<std::shared_mutex> lock(smtx);
    std::cout<<"Data has been read = "<<shared_data<<'\n';
}

void writer()
{
    std::unique_lock<std::shared_mutex> lock(smtx);
    ++shared_data;
    std::cout<<"Data has been written = "<<shared_data<<'\n';
}

void printOdd()
{
    while(value <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx1);
        cv1.wait(lock, [](){return value % 2 == 1;});
        if(value > MAX)
        {
            std::cout<<"Max has been reached.\n";
            break;
        }
        std::cout<<value<<'\n';
        ++value;
        cv1.notify_one();
    }
}

void printEven()
{
    while(value <= MAX)
    {
        std::unique_lock<std::mutex> lock(mtx1);
        cv1.wait(lock, [](){return value % 2 == 0;});
        if(value > MAX)
        {
            std::cout<<"Max has been reached.\n";
            break;
        }
        std::cout<<value<<'\n';
        ++value;
        cv1.notify_one();
    }
}

void producerQ()
{
    std::lock_guard<std::mutex> lock(mtx2);
    for(int i = 0; i < 5; ++i)
    {
        Q.push(i);
    }
    queue_ready = true;
    CV2.notify_one();
}

void consumerQ()
{
    while(true)
    {
        std::unique_lock<std::mutex> lock(mtx2);
        CV2.wait(lock,[](){return queue_ready;});
        int a = Q.front();
        Q.pop();
        std::cout<<"value = "<<a<<'\n';
        if(Q.empty() == true)
        {
            std::cout<<"queue is empty.\n";
            break;
        }
    }
}

class B;

class A
{
    public:
    std::shared_ptr<B> ptr_B;
    public:
    explicit A() noexcept
    {
        std::cout<<"A::A is caled.\n";
    }

    ~A() noexcept
    {
        std::cout<<"A::~A is called.\n";
    }
};

class B
{
    public:
    std::weak_ptr<A> ptr_A;
    public:
    explicit B() noexcept
    {
        std::cout<<"B::B is caled.\n";
    }

    ~B() noexcept
    {
        std::cout<<"B::~B is called.\n";
    }
};

int main()
{
    std::thread T1(producer);
    std::thread T2(consumer);
    if(T1.joinable())
    {
        T1.join();
    }
    if(T2.joinable())
    {
        T2.join();
    }

    std::thread T3(reader);
    std::thread T4(reader);
    std::thread T5(writer);
    std::thread T6(reader);
    if(T3.joinable())
    {
        T3.join();
    }
    if(T4.joinable())
    {
        T4.join();
    }
    if(T5.joinable())
    {
        T5.join();
    }
    if(T6.joinable())
    {
        T6.join();
    }
    std::cout<<"Print even and Odd numbers.\n";
    std::thread T7(printOdd);
    std::thread T8(printEven);
    if(T7.joinable())
    {
        T7.join();
    }
    if(T8.joinable())
    {
        T8.join();
    }
    std::cout<<"Queue based producer and consumer.\n";
    std::thread T9(producerQ);
    std::thread T10(consumerQ);
    if(T9.joinable())
    {
        T9.join();
    }
    if(T10.joinable())
    {
        T10.join();
    }

    std::shared_ptr<A> SPA(new A());
    std::shared_ptr<B> SPB(new B());
    SPA->ptr_B = SPB;
    SPB->ptr_A = SPA;
    return 0;
}