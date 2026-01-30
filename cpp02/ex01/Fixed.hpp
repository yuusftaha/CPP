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
    Fixed& operator=(const Fixed& fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;
    ~Fixed();
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif