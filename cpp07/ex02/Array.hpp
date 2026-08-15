#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array 
{
    private:
        T*              elements;
        unsigned int    size;

    public:
        // Kurucular ve Yıkıcılar
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        // Operatör Aşırı Yüklemeleri (Subscript)
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        // Üye Fonksiyonlar
        unsigned int size() const;

        // Exception Sınıfı
        class OutOfBoundsException : public std::exception {
        public:
            virtual const char* what() const throw();
        };
};

// SİHİRLİ SATIR: Derleyici gövdeleri bulabilsin diye .tpp dosyasını EN ALTA ekliyoruz.
#include "Array.tpp"

#endif