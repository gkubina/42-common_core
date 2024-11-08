/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 09:12:33 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria (void)
{
	std::cout << "Default AMateria constructor called" << std::endl;
	this->type = "Default_Materia";
}

AMateria::AMateria (AMateria const & src)
{
	std::cout << "Copy AMateria constructor called" << std::endl;
	this->type = src.type;
}

AMateria::AMateria (std::string const & type) : type(type)
{
	std::cout << "AMateria constructor called with type: " << type << "." << std::endl;
}

AMateria::~AMateria (void)
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

AMateria* AMateria::clone() const
{
	std::cout << "AMateria Clone pure virtual fonction." << std::endl;
	// AMateria *ret = new AMateria; // not allowed because AMateria is pure virtual
	//return ret;
	return NULL;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria use virtual fonction on " << target.getName() << "." << std::endl;
}

std::string const & AMateria::getType(void) const
{
	return this->type;
}