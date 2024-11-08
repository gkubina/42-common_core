/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/01 12:12:32 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog (void) // : Animal() (the constructor of the parent class) is automatically added by the compiler
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog (Dog const & src) : Animal(src)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->type = src.type;
}

Dog::~Dog (void)
{
	std::cout << "Dog Destructor called" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << this->type << " makes : WoufWouf." << std::endl;
}