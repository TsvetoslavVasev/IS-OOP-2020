#include <iostream>
using namespace std;
//Да се напише програма, която пита потребителя за n на брой числа. Трябва да заделите динамично толкова на брой елементи(не повече!) колкото потребителя ще въведе. Напишете функции, които намират средното, най-малкия и най-големия елемент в този масив. Изпишете тези стойности на конзолата.

double getAverage(int* numbers, int size)
{
    double sum = 0;
    for(int i=0; i<size; i++)
    {
        sum += numbers[i];
    }
    return sum/size;
}
int getMin(int* numbers, int size)
{
    if(size < 1) {
        return -1;
    }
    int min = numbers[0];
    
    for(int i=0; i<size; i++)
    {
        if(numbers[i] < min) min = numbers[i];
    }
    
    return min;
}
int getMax(int* numbers, int size)
{
    if(size < 1) {
        return -1;
    }
    int max = numbers[0];
    
    for(int i=0; i<size; i++)
    {
        if(numbers[i] > max) max = numbers[i];
    }
    
    return max;
}
int main()
{
    int count;
    cout<<"Count: ";
    cin>>count;
    
    int* numbers = new int[count];
    for(int i=0; i <count; i++)
    {
        cout<<"numbers[" << i << "] = ";
        cin>>numbers[i];
    }
    
    double avg = getAverage(numbers,count);
    int min  = getMin(numbers,count);
    int max = getMax(numbers,count);
    
    cout<< "\nAverage: "<<avg<<endl;
    cout<<"/nMin: "<<min<<endl;
    cout<<"/nMax: "<<max<<endl;
    
    delete[] numbers;
}
