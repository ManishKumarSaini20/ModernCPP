#include<iostream>
#include<memory>
#include<mutex>

class Singleton
{
    static std::mutex mtx;
    static std::unique_ptr<Singleton> instance;
    Singleton()
    {
        std::cout<<"Private constructor.\n";
    }

    public:
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator = (Singleton&&) = delete;
    ~Singleton()
    {
        std::cout<<"Destructor called.\n";
    }
    static Singleton& CreateInstance()
    {
        std::lock_guard<std::mutex> lock(mtx);
        if(instance == nullptr)
        {
            std::cout<<"Creating instance.\n";
            instance = std::unique_ptr<Singleton>(new Singleton());
        }
        else
        {
            std::cout<<"Instance already created.\n";
        }
        return *instance;
    }

    void Print()
    {
        std::cout<<"Hello from Singleton.\n";
    }
};

std::mutex Singleton::mtx;
std::unique_ptr<Singleton> Singleton::instance = nullptr;


class SingletonM
{
    SingletonM()
    {
        std::cout<<"Private constructor.\n";
    }

    public:
    SingletonM(const SingletonM&) = delete;
    SingletonM& operator = (const SingletonM&) = delete;
    SingletonM(SingletonM&&) = delete;
    SingletonM& operator = (SingletonM&&) = delete;
    ~SingletonM()
    {
        std::cout<<"Destructor called.\n";
    }
    static SingletonM& CreateInstance()
    {
        static SingletonM instance;
        return instance;
    }

    void Print()
    {
        std::cout<<"Hello from Singleton.\n";
    }
};

int main()
{
    Singleton& ins1 = Singleton::CreateInstance();
    Singleton& ins2 = Singleton::CreateInstance();
    ins1.Print();
    ins2.Print();

    SingletonM& ins3 = SingletonM::CreateInstance();
    SingletonM& ins4 = SingletonM::CreateInstance();
    ins3.Print();
    ins4.Print();

    return 0;
}