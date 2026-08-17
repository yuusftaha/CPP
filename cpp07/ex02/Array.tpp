#include"Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : elements(NULL), _size(0) 
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) 
{
    if (this != &other) 
    {
        if (elements)
            delete[] elements;
        
        _size = other._size;
        
        if (_size > 0) 
        {
            elements = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                elements[i] = other.elements[i];
        } 
        else
            elements = NULL;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() 
{
    if (elements) 
        delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const 
{
    if (index >= _size) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
    return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() 
{
    return "Error: Array index out of bounds!";
}