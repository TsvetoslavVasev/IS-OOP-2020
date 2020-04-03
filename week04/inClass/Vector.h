#include <iostream>
#include <cassert>
using std::cin;
using std::cout;

template <typename T>
class Vector {
private:
    T* values;
    size_t count;
    size_t capacity;
    void copy(const Vector& other);
    void erase();
    void resize();
public:
    Vector();
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
    
    void push_back(T element);
    void push(size_t index, T element);
    void pop_back();
    void pop_front();
    
    T operator[](size_t index) const;
    void print() const;
    size_t size() const;
};


// Private methods
template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
    this->values = new T[other.capacity];
    for (size_t i = 0; i < other.count; i++) {
        this->values[i] = other.values[i];
    }
    this->count = other.count;
    this->capacity = other.capacity;
}

template <typename T>
void Vector<T>::erase()
{
    delete[] this->values;
}

template <typename T>
void Vector<T>::resize()
{
    this->capacity = this->capacity*2 + 1;
    T* temp = new T[this->capacity];
    for(size_t i = 0; i < this->count; i++)
    {
        temp[i] = this->values[i];
    }
    this->erase();
    values = temp;
}

// Big four
template <typename T>
Vector<T>::Vector()
{
    this->capacity = 0;
    this->count = 0;
    this->values = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
    this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    
    return *this;
}

template <typename T>
Vector<T>::~Vector()
{
    this->erase();
}

// Public methods ;
template <typename T>
void Vector<T>::push_back(T element)
{
    if(this->count >= this->capacity)
    {
        this->resize();
    }
    this->values[count++] = element;
}

template <typename T>
void Vector<T>::push(size_t index, T element)
{
    
    if(this->count >= this->capacity)
    {
        this->resize();
    }
    this->count++;
    
    for( size_t i = count; i > index + 1; i--)
    {
        this->values[i] = this->values[i-1];
    }
    this->values[index] = element;
}

template <typename T>
void Vector<T>::pop_back()
{
    this->count--;
}

template <typename T>
void Vector<T>::pop_front()
{
    // T temp = this->values[1];
    for(size_t i = 0; i < this->count-1; i++)
    {
        this->values[i]=this->values[i+1];
        // this->values[i] = temp;
        // temp = this->values[i+1];
    }
    this->count--;
}

template <typename T>
T Vector<T>::operator[](size_t index) const
{
    assert(index < this->count);
    return this->values[index];
}

template <typename T>
void Vector<T>::print()const
{
    for(size_t i = 0; i < this->count; i++)
    {
        cout<<this->values[i]<<" ";
    }
}

template <typename T>
size_t Vector<T>::size() const
{
    return this->count;
}


