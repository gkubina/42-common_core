/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 12:31:18 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure (void)
{
	std::cout << "Default Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure (Cure const & src): AMateria(src)
{
	std::cout << "Copy Cure constructor called" << std::endl;
	// this->type = src.type;
}

Cure::~Cure (void)
{
	std::cout << "Cure Destructor called" << std::endl;
}

Cure & Cure::operator=(Cure const & rhs)
{
	std::cout << "Cure assignment operator called" << std::endl;
	//this->type = rhs.type;
	(void) rhs;
	return *this;
}

Cure* Cure::clone() const
{
	std::cout << "Cure Clone fonction called." << std::endl;
	Cure *ret = new Cure;
	return ret;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

