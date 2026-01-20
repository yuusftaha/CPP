#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->num = value << this->fixed_point;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->num = round(value * (1 << this->fixed_point));
}

Fixed::Fixed(const Fixed& fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

std::ostream &operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
    return o;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    std::cout << "Copy assignment operator called" << std::endl;
    
    if (this != &fixed)
        this->num = fixed.getRawBits();
    return *this;
}

float Fixed::toFloat() const
{
	return (float)this->num / (1 << this->fixed_point);
}

int Fixed::toInt() const
{
	return this->num >> this->fixed_point;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->num;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->num = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}