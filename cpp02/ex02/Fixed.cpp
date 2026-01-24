#include "Fixed.hpp"

Fixed::Fixed() : num(0)
{

}

Fixed::Fixed(const int value)
{
	this->num = value << this->fixed_point;
}

Fixed::Fixed(const float value)
{
	this->num = round(value * (1 << this->fixed_point));
}

Fixed::Fixed(const Fixed& fixed)
{
    *this = fixed;
}

std::ostream &operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
    return o;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{ 
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

int Fixed::getRawBits(void) const 
{
    return this->num;
}

void Fixed::setRawBits(int const raw) 
{
    this->num = raw;
}

Fixed::~Fixed()
{

}

bool Fixed::operator>(const Fixed &value) const
{
    return this->getRawBits() > value.getRawBits();
}

bool Fixed::operator<(const Fixed &value) const
{
    return this->getRawBits() < value.getRawBits();
}

bool Fixed::operator>=(const Fixed &value) const
{
    return this->getRawBits() >= value.getRawBits();
}

bool Fixed::operator<=(const Fixed &value) const
{
    return this->getRawBits() <= value.getRawBits();
}

bool Fixed::operator==(const Fixed &value) const
{
    return this->getRawBits() == value.getRawBits();
}

bool Fixed::operator!=(const Fixed &value) const
{
    return this->getRawBits() != value.getRawBits();
}

Fixed Fixed::operator+(const Fixed &value) const
{
    return Fixed(this->toFloat() + value.toFloat());
}

Fixed Fixed::operator-(const Fixed &value) const
{
    return Fixed(this->toFloat() - value.toFloat());
}

Fixed Fixed::operator*(const Fixed &value) const
{
    return Fixed(this->toFloat() * value.toFloat());
}

Fixed Fixed::operator/(const Fixed &value) const
{
    return Fixed(this->toFloat() / value.toFloat());
}

Fixed& Fixed::operator++() {
    this->num++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->num++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->num--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->num--;
    return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}