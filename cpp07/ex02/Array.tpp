#include"Array.hpp"


template <typename T>
Array<T>::Array() : elements(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), size(n) {}

template <typename T>
Array<T>::Array(const Array<T>& other) : elements(NULL), size(0) 
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) 
{
    if (this != &other) {
        if (elements) {
            delete[] elements;
        }
        
        size = other.size;
        
        if (size > 0) {
            elements = new T[size]();
            for (unsigned int i = 0; i < size; i++) {
                elements[i] = other.elements[i];
            }
        } else {
            elements = NULL;
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() 
{
    if (elements) {
        delete[] elements;
    }
}

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
    if (index >= size) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const 
{
    if (index >= size) {
        throw OutOfBoundsException();
    }
    return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
    return size;
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() 
{
    return "Hata: Dizi sinirlarinin disina cikildi (Out of bounds)!";
}