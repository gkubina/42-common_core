/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/08/01 17:32:46 by georg            ###   ########.fr       */
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

	int 	getRawBits( void ) const;
	void 	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream & os, const Fixed & rhs);

#endif
