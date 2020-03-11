
#include <iostream>
using namespace std;

// Да се направи клас Person, който в себе си има полета за име и години. Нека този клас има реализирани:

// конструктор по подразбиране
// конструктор с параметри
// деструктор
// get-ъри и set-ъри
// функция, която принтира информацията на човека

class Person {
private:
    char* name;
    int age;
    void copy(const Person& other)
    {
        this->name = new char[strlen(other.name) + 1]; // '\0'
        for(int i = 0; i < strlen(other.name) + 1; i++)
        {
            this->name[i] = other.name[i];
        }
    }
    void erase()
    {
        delete[] this->name;
    }
public:
    Person()
    {
        this->name = nullptr;
        this->age = 0;
    }
    Person(const char* name, int age)
    {
        this->name = new char[strlen(name) + 1]; // '\0'
        for(int i =0; i< strlen(name) + 1; i++)
        {
            this->name[i] = name[i];
        }
        this->age = age;
    }
    Person(const Person& other)
    {
        this->copy(other);
        this->age = other.age;
    }
    
    Person& operator=(const Person& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        
        return *this;
    }
    
    ~Person()
    {
        cout<<"Destroyed";
        this->erase();
    }
    
    void setAge(const int age)
    {
        this->age = age;
    }
    void setName(const char* name)
    {
        this->erase();
        this->name = new char[strlen(name) + 1];
        for(int i = 0; i < strlen(name) + 1; i++)
        {
            this->name[i] = name[i];
        }
    }
    char* getName()const
    {
        return this->name;
    }
    int getAge() const
    {
        return this->age;
    }
    
    void printInfo() const
    {
        cout<< "Age: "<< this->age<<endl;
        cout<<"Name: "<<this->name<<endl;
    }
};

int main()
{
    Person person1("Ivan Panayotov",23);
    Person person2("Bogdan Aleksandrov",2000);
    
    person1.printInfo();
    person2.printInfo();
}
