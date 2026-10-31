#include<iostream>
#include<cstring>
#include<string>
/*
class CMansih
{
    char* m_ptr;
    public:
    explicit CMansih(const char* ptr = "") noexcept : m_ptr(nullptr)
    {
        std::cout<<"Constructor.\n";
        m_ptr = new char[strlen(ptr) + 1];
        strcpy(m_ptr, ptr);
    }

    ~CMansih() noexcept
    {
        std::cout<<"Destructor.\n";
        delete [] m_ptr;
    }

    CMansih(const CMansih& obj)
    {
        std::cout<<"Copy constructor.\n";
        m_ptr = new char[strlen(obj.m_ptr)+1];
        strcpy(m_ptr,obj.m_ptr);
    }

    CMansih& operator = (const CMansih& obj)
    {
        std::cout<<"Assignment operator.\n";
        if(&obj == this)
        {
            return *this;
        }
        char* temp = new char[strlen(obj.m_ptr)+1];
        strcpy(temp, obj.m_ptr);
        delete[] m_ptr;
        m_ptr = temp;
        return *this;
    }

    CMansih(CMansih&& obj) noexcept
    {
        std::cout<<"Move constructor.\n";
        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;
    }

    CMansih& operator = (CMansih&& obj) noexcept
    {
        std::cout<<"MOve assignment operator.\n";
        if(&obj == this)
        {
            return *this;
        }
        delete[] m_ptr;
        m_ptr = obj.m_ptr;
        obj.m_ptr = nullptr;
        return *this;
    }

    void Display() const
    {
        if(m_ptr != nullptr)
        {
            std::cout<<m_ptr<<std::endl;
        }
    }
};

int main()
{
    CMansih obj("Hello");
    obj.Display();
    return 0;
}
*/

class CMansih
{
    std::string m_ptr;
    public:
    explicit CMansih(const std::string& ptr = "") noexcept : m_ptr(ptr)
    {
        std::cout<<"Constructor.\n";
    }

    void Display() const
    {
        std::cout<<m_ptr<<std::endl;
    }
};

class FileHandler
{
public:

    FileHandler()
    {
        std::cout
            << "File Opened\n";
    }

    ~FileHandler()
    {
        std::cout
            << "File Closed\n";
    }
};

int main()
{
    CMansih obj1("Hello");

    CMansih obj2(obj1);

    CMansih obj3("World");
    obj3 = obj1;

    CMansih obj4(std::move(obj1));

    CMansih obj5("ABC");
    obj5 = std::move(obj2);

    obj3.Display();
    obj4.Display();
    obj5.Display();

    {
        FileHandler fh;
    }

    return 0;
}