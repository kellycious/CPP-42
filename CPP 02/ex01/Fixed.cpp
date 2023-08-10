/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:45:11 by khuynh            #+#    #+#             */
/*   Updated: 2023/08/10 15:17:02 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bits));
}

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Assignation operator called" << std::endl;
	this->value = f.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

std::ostream& operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}