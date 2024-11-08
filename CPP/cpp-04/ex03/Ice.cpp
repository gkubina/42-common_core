/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 12:31:10 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice (void)
{
	std::cout << "Default Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice (Ice const & src): AMateria(src)
{
	std::cout << "Copy Ice constructor called" << std::endl;
	//this->type = src.type;
}

Ice::~Ice (void)
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	//this->type = rhs.type;
	(void) rhs;
	std::cout << "Ice assignment operator called" << std::endl;	
	return *this;
}

Ice* Ice::clone() const
{
	std::cout << "Ice Clone fonction called." << std::endl;
	Ice *ret = new Ice;
	return ret;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

