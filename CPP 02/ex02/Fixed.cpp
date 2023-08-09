/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:45:11 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/09 00:26:02 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0){}

Fixed::Fixed(const Fixed &f)
{
	*this = f;
}

Fixed::Fixed(const int value)
{
	this->value = value << this->bits;
}

Fixed::Fixed(const float value)
{
	this->value = std::roundf(value * (1 << this->bits));
}

Fixed &Fixed::operator=(const Fixed &f)
{
	this->value = f.getRawBits();
	return *this;
}

Fixed::~Fixed(){}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int Fixed::toInt(void) const
{
	return this->value >> this->bits;
}

int Fixed::getRawBits(void) const
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

bool Fixed::operator>(const Fixed &f) const
{
	return this->toFloat() > f.toFloat();
}

bool Fixed::operator<(const Fixed &f) const
{
	return this->toFloat() < f.toFloat();
}

bool Fixed::operator>=(const Fixed &f) const
{
	return this->toFloat() >= f.toFloat();
}

bool Fixed::operator<=(const Fixed &f) const
{
	return this->toFloat() <= f.toFloat();
}

bool Fixed::operator==(const Fixed &f) const
{
	return this->toFloat() == f.toFloat();
}

bool Fixed::operator!=(const Fixed &f) const
{
	return this->toFloat() != f.toFloat();
}

Fixed Fixed::operator+(const Fixed &f) const
{
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f) const
{
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f) const
{
	return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++value;
	return tmp;
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream& operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}