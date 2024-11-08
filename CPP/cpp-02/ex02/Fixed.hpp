/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/08/01 18:45:17 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
	int	_value;
	static const int	_fract_bits = 8;

	public:
		Fixed ( void );
		Fixed ( Fixed const & src );
		Fixed ( int const src );
		Fixed ( float const src );
		~Fixed ( void );

	Fixed & operator=( Fixed const & rhs );

	// Comparative operators
	bool operator<( Fixed const & rhs );
	bool operator>( Fixed const & rhs );
	bool operator<=( Fixed const & rhs );
	bool operator>=( Fixed const & rhs );
	bool operator==( Fixed const & rhs );
	bool operator!=( Fixed const & rhs );

	// Arithmetic operators
	Fixed operator+( Fixed const & rhs ) const;
	Fixed operator-( Fixed const & rhs ) const;
	Fixed operator*( Fixed const & rhs ) const;
	Fixed operator/( Fixed const & rhs ) const;

	// Incr-Decr operators
	Fixed & operator++( void );
	Fixed & operator--( void );
	Fixed operator++( int value);
	Fixed operator--( int value);

	// Compare fontions

	static Fixed const & min ( Fixed const & first, Fixed const & second);
	static Fixed & min ( Fixed & first, Fixed & second);
	static Fixed const & max ( Fixed const & first, Fixed const & second);
	static Fixed & max ( Fixed & first, Fixed & second);


	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream & os, const Fixed & rhs);

#endif
