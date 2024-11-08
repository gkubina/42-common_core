/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/08/01 21:06:25 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed	a;
	Fixed	const b ( Fixed( 5.05f ) * Fixed( 2 ) );
	
//	Fixed	c (4.1f);
//	Fixed	d (-2.05f);

//	std::cout << "C=" << c << " D=" << d << " Div C/D= " << c/d << std::endl;
//	std::cout << "C=" << c << " D=" << d << " Mult C*D= " << c*d << std::endl;
//	std::cout << "C=" << c << " D=" << d << " Sub C-D= " << c-d << std::endl;
//	std::cout << "C=" << c << " D=" << d << " Add C+D= " << c+d << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
//	std::cout << d << std::endl;
//	std::cout << --d << std::endl;
//	std::cout << d << std::endl;
//	std::cout << d-- << std::endl;
//	std::cout << d << std::endl;
	

	std::cout << Fixed::max( a, b ) << std::endl;
//	std::cout << Fixed::min( c, d ) << std::endl;
	return 0;
}