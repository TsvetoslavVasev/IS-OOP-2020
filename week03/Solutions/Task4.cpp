#include <iostream>
#include<fstream>
using namespace std;

//Да се направи клас Филм, който в себе си има полетата име, режисьор и продължителноста на филма. За този клас трябва да се реализират:

//конструктор по подразбиране
//конструктор с параметри
//деструктор
//оператор за присвояване

class Movie
{
private:
    char* name;
    char* director;
    int minutes;
    
    void copy(const Movie& other)
    {
        this->name = new char[strlen(other.name) + 1];
        this->director = new char[strlen(other.director) + 1];
        for(int i = 0; i < strlen(other.name) + 1; i++)
        {
            this->name[i] = other.name[i];
        }
        for(int i = 0; i < strlen(other.director) + 1; i++)
        {
            this->director[i] = other.director[i];
        }
        this->minutes = other.minutes;
    }
    void erase()
    {
        delete[] this->name;
        delete[] this->director;
    }
public:
    Movie()
    {
        this->name = nullptr;
        this->director = nullptr;
        this->minutes = 0;
    }
    
    Movie(const char* name, const char* director, const int minutes)
    {
        this->name = new char[strlen(name) + 1];
        this->director = new char[strlen(director) + 1];
        for(int i = 0; i < strlen(name) + 1; i++)
        {
            this->name[i] = name[i];
        }
        for(int i = 0; i < strlen(director) + 1; i++)
        {
            this->director[i] = director[i];
        }
        
        this->minutes = minutes;
    }
    
    Movie(const Movie& other)
    {
        this->copy(other);
    }
    
    Movie& operator=(const Movie& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }
        return *this;
    }
    
    bool operator==(const Movie& other)
    {
        return this->minutes == other.minutes &&
               !strcmp(this->name,other.name) &&
               strcmp(this->director,other.director) == 0;
    }
    
    ~Movie()
    {
        this->erase();
    }
    
    void print()const
    {
        cout<<"Name: "<<this->name<<endl;
        cout<<"Director: "<< this->director<<endl;
        cout<<"Duration: "<< this->minutes<<" minutes \n";
    }
};
int main()
{
    Movie movie("Fast and Furious","Bogdan Aleksandrov",120);
    Movie movie2(movie);
    
    movie.print();
    movie2.print();
    
    cout<<"\n "<<(movie==movie2)<<endl;
}
