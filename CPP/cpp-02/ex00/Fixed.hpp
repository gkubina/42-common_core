/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:46:33 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
	int	_value;
	static const int	_fract_bits = 8;

	public:
		Fixed (void);
		Fixed (Fixed const & src);
		~Fixed (void);

	Fixed & operator=(Fixed const & rhs);

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
