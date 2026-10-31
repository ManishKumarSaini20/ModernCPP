#include<iostream>
#include<vector>

class observer
{
    public:
    virtual void update(int value) = 0;
    virtual ~observer()
    {
        std::cout<<"Observer destructor called.\n";
    }
};

class Display : public observer
{
    public:
    void update(int value) override
    {
        std::cout<<"Display updated with value: "<<value<<"\n";
    }
};

class subject
{
    std::vector<observer*> observers;
    public:
    void attach(observer* observer)
    {
        observers.push_back(observer);
    }

    void notify(int value)
    {
        for(auto elem : observers)
        {
            elem->update(value);
        }
    }
};

int main()
{ 
    subject sensors;
    Display objdisplay1;
    Display objdisplay2;
    sensors.attach(&objdisplay1);
    sensors.attach(&objdisplay2);
    sensors.notify(100);
    return 0;
}