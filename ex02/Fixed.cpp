/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:42 by huidris           #+#    #+#             */
/*   Updated: 2025/08/06 19:07:06 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0){}

Fixed::Fixed(const int value)
{
	_value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	_value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

//Comparison Operators
bool	Fixed::operator>(Fixed fixed)const
{
	return(this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed)const
{
	return(this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed)const
{
	return(this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed)const
{
	return(this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed)const
{
	return(this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed)const
{
	return(this->toFloat() != fixed.toFloat());
}


//Arithmetic Operator
float Fixed::operator+(Fixed fixed)const
{
	return(this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed)const
{
	return(this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed)const
{
	return(this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed fixed)const
{
	return(this->toFloat() / fixed.toFloat());
}

//Increment Operator
Fixed Fixed::operator++()
{
	++this->_value;
	return (*this);
}

Fixed Fixed::operator--()
{
	--this->_value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_value;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_value;
	return (temp);
}

//Public Overload
Fixed &Fixed::min(Fixed &input1, Fixed &input2)
{
	if (input1.toFloat() <= input2.toFloat())
		return (input1);
	else
		return (input2);
}

Fixed &Fixed::max(Fixed &input1, Fixed &input2)
{
	if (input1.toFloat() >= input2.toFloat())
		return (input1);
	else
		return (input2);
}

Fixed const &Fixed::min(Fixed const &input1, Fixed const &input2)
{
	if (input1.toFloat() <= input2.toFloat())
		return (input1);
	else
		return (input2);
}

Fixed const &Fixed::max(Fixed const &input1, Fixed const &input2)
{
	if (input1.toFloat() >= input2.toFloat())
		return (input1);
	else
		return (input2);
}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
	return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
