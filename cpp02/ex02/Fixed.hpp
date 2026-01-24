#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
    int num;
    static const int fixed_point = 8;

    public:
    Fixed();
    Fixed(const Fixed& fixed);
    Fixed(const int value);
    Fixed(const float value);    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;
    ~Fixed();
    Fixed& operator=(const Fixed& fixed);

    bool operator>(const Fixed &value) const;
    bool operator<(const Fixed &value) const;
    bool operator>=(const Fixed &value) const;
    bool operator<=(const Fixed &value) const;
    bool operator==(const Fixed &value) const;
    bool operator!=(const Fixed &value) const;

    Fixed operator+(const Fixed &value) const;
    Fixed operator-(const Fixed &value) const;
    Fixed operator*(const Fixed &value) const;
    Fixed operator/(const Fixed &value) const;

    Fixed& operator++();    // Pre-increment (++a)
    Fixed operator++(int);  // Post-increment (a++)
    Fixed& operator--();    // Pre-decrement (--a)
    Fixed operator--(int);  // Post-decrement (a--)

    static Fixed& min(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif