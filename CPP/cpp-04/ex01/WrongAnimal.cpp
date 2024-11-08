/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 13:13:10 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal (void)
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	this->type = "Default_WrongAnimal";
}

WrongAnimal::WrongAnimal (WrongAnimal const & src)
{
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	this->type = src.type;
}

WrongAnimal::~WrongAnimal (void)
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal " << this->type << " makes a default sound." << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}