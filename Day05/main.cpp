#include <iostream>
#include <vector>
#include <memory>

template<typename T>
using Vect = std::vector<T>;

class Employee
{
public:
    Employee()
    {
        std::cout << "Constructor\n";
    }

    ~Employee()
    {
        std::cout << "Destructor\n";
    }
};

class B;

class A
{
public:
std::shared_ptr<B> ptrB;
    A()
    {
        std::cout << "A Constructor\n";
    }

    ~A()
    {
        std::cout << "A Destructor\n";
    }
};

class B
{
public:
    std::weak_ptr<A> ptrA;
    B()
    {
        std::cout << "B Constructor\n";
    }

    ~B()
    {
        std::cout << "B Destructor\n";
    }
};

int main()
{
    Vect<int> v1{10,20,30,40,50};
    for(const int& elem : v1)
    {
        std::cout << elem << std::endl;
    }

    std::cout<<"size of v1: "<<v1.size()<<std::endl;
    std::cout<<"capacity of v1: "<<v1.capacity()<<std::endl;
    std::cout<<"front of v1: "<<v1.front()<<std::endl;
    std::cout<<"back of v1: "<<v1.back()<<std::endl;
    std::cout<<"max size of v1: "<<v1.max_size()<<std::endl;
    std::cout<<"iterate through v1 using iterator: "<<std::endl;
    for(Vect<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    {
        std::cout<<"*it = "<<*it<<std::endl;
    }
    std::cout<<"iterate through v1 using const_iterator: "<<std::endl;
    for(Vect<int>::const_iterator it = v1.cbegin(); it != v1.end(); ++it)
    {
        std::cout<<"*it = "<<*it<<std::endl;
    }

    Vect<int> v2;
    v2.reserve(10);
    std::cout<<"size of v2: "<<v2.size()<<std::endl;
    std::cout<<"capacity of v2: "<<v2.capacity()<<std::endl;
    v2.resize(5);
    std::cout<<"size of v2 after resize: "<<v2.size()<<std::endl;
    std::cout<<"capacity of v2 after resize: "<<v2.capacity()<<std::endl;
    v2.insert(v2.begin(), 100);
    std::cout<<"size of v2 after insert: "<<v2.size()<<std::endl;
    std::cout<<"capacity of v2 after insert: "<<v2.capacity()<<std::endl;
    v2.insert(v2.begin()+1, 200);
    std::cout<<"size of v2 after insert: "<<v2.size()<<std::endl;
    std::cout<<"capacity of v2 after insert: "<<v2.capacity()<<std::endl;
    for(const int& elem : v2)
    {
        std::cout << elem << std::endl;
    }
    v2.erase(v2.begin());
    std::cout<<"size of v2 after erase: "<<v2.size()<<std::endl;
    std::cout<<"capacity of v2 after erase: "<<v2.capacity()<<std::endl;
    for(const int& elem : v2)
    {
        std::cout << elem << std::endl;
    }
    //Employee* p1 = new Employee();
    std::unique_ptr<Employee> emp = std::make_unique<Employee>();
    std::unique_ptr<Employee> emp2 = std::move(emp);

    std::shared_ptr<Employee> emp3 = std::make_shared<Employee>();
    std::shared_ptr<Employee> emp4 = emp3;
    std::shared_ptr<Employee> emp5 = emp4;
    std::cout<<"emp3 use count: "<<emp4.use_count()<<std::endl;

    std::shared_ptr<int> p1 = std::make_shared<int>(100);

    std::cout<< p1.use_count()<< '\n';

    {
        std::shared_ptr<int> p2 = p1;

        std::cout<< p1.use_count()<< '\n';
    }

    std::cout<< p1.use_count()<< '\n';

    std::shared_ptr<A> pteA = std::make_shared<A>();
    std::shared_ptr<B> pteB = std::make_shared<B>();
    std::cout<<"pteA use count: "<<pteA.use_count()<<std::endl;
    std::cout<<"pteB use count: "<<pteB.use_count()<<std::endl;
    pteA->ptrB = pteB;
    pteB->ptrA = pteA;
    std::cout<<"pteA use count after setting pointers: "<<pteA.use_count()<<std::endl;
    std::cout<<"pteB use count after setting pointers: "<<pteB.use_count()<<std::endl;

    return 0;
}