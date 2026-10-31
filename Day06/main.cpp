#include<iostream>
#include<memory>


class B;
class A
{
    public:
    std::shared_ptr<B> ptrB;
    public:
    A()
    {
        std::cout<<"A::A.\n";
    }

    ~A()
    {
        std::cout<<"A::~A.\n";
    }
};

class B
{
    public:
    std::weak_ptr<A> ptrA;
    public:
    B()
    {
        std::cout<<"B::B.\n";
    }

    ~B()
    {
        std::cout<<"B::~B.\n";
    }
};

int main()
{
    std::shared_ptr<A> ptrAA = std::make_shared<A>();
    std::shared_ptr<B> ptrBB = std::make_shared<B>();
    ptrAA->ptrB = ptrBB;
    ptrBB->ptrA = ptrAA;
    return 0;
}