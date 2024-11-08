/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/08/01 21:14:11 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed (void) : _value(0)
{
//	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed (Fixed const & src)
{
//	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed (int const src) : _value(src * 256)
{
//	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed (float const src) : _value((int)roundf(src * 256))
{
//	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed (void)
{
//	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator=( Fixed const & rhs )
{
//	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(rhs.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
}

void Fixed::setRawBits( int const raw )
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	float ret = (float)this->_value / 256;
	return (ret);
}

int		Fixed::toInt( void ) const
{
	return (this->_value / 256);
//	return (this->_value >> this->_fract_bits);
}

std::ostream& operator<<(std::ostream & os, const Fixed & rhs)
{
	os << rhs.toFloat();
	return (os);
}

// Comparative operators

bool Fixed::operator<( Fixed const & rhs )
{
	return (this->_value < rhs.getRawBits());
}
bool Fixed::operator>( Fixed const & rhs )
{
	return (this->_value > rhs.getRawBits());
}
bool Fixed::operator<=( Fixed const & rhs )
{
	return (this->_value <= rhs.getRawBits());
}
bool Fixed::operator>=( Fixed const & rhs )
{
	return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator==( Fixed const & rhs )
{
	return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=( Fixed const & rhs )
{
	return (this->_value != rhs.getRawBits());
}


// Arithmetic operators

Fixed Fixed::operator+( Fixed const & rhs ) const
{
	Fixed ret;
	ret.setRawBits(this->_value + rhs.getRawBits());	
	return (ret);
}

Fixed Fixed::operator-( Fixed const & rhs ) const
{
	Fixed ret;
	ret.setRawBits(this->_value - rhs.getRawBits());	
	return (ret);
}

Fixed Fixed::operator*( Fixed const & rhs ) const
{
	Fixed ret;
	ret.setRawBits((this->_value * rhs.getRawBits()) / 256);
	return (ret);
}

Fixed Fixed::operator/( Fixed const & rhs ) const
{
	Fixed ret;
	ret.setRawBits((this->_value * 256) / rhs.getRawBits()); 
	return (ret);
}

// Incr-Decr operators

Fixed & Fixed::operator++( void )
{
	++this->_value; 
	return (*this);
}

Fixed & Fixed::operator--( void )
{
	--this->_value; 
	return (*this);
}

Fixed Fixed::operator++( int value)
{
	(void) value;
	Fixed ret;
	ret.setRawBits(this->_value);
	++this->_value;
	return (ret);
}

Fixed Fixed::operator--( int value)
{
	(void) value;
	Fixed ret;
	ret.setRawBits(this->_value);
	--this->_value;
	return (ret);
}

// Compare fonctions

Fixed const & Fixed::min ( Fixed const & first, Fixed const & second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed & Fixed::min ( Fixed & first, Fixed & second)
{
	if (first.getRawBits() < second.getRawBits())
		return (first);
	return (second);
}

Fixed const & Fixed::max ( Fixed const & first, Fixed const & second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}

Fixed & Fixed::max ( Fixed & first, Fixed & second)
{
	if (first.getRawBits() > second.getRawBits())
		return (first);
	return (second);
}