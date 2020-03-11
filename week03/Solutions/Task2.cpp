#include <iostream>
using namespace std;

// Напишете имплементация на strcpy(char* dest, const char* src) функцията.

int mystrlen(const char* str)
{
    int i = -1;
    while(str[++i]);
    return i;
}
void mystrcpy(char*& destination, const char* source)
{
    delete[] destination;
    
    int length = mystrlen(source);
    
    destination = new char[length + 1]; // '\0'
    for(int i = 0; i< length; i++)
    {
        destination[i] = source[i];
    }
}

1,2,3,4

int main()
{
    const char* src = "Ceco";
    char* dest = nullptr;
    mystrcpy(dest,src);
    
    cout<<"Source: "<< src<<endl;
    cout<<"Dest: "<< dest<<endl;
}
