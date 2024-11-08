/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/01 12:03:29 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog (void) : AAnimal()
{
	std::cout << "Default Dog with Brain constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog (Dog const & src) : AAnimal(src)
{
	std::cout << "Copy Dog with Brain constructor called" << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Dog::~Dog (void)
{
	std::cout << "Dog Destructor called" << std::endl;
	delete this->brain;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignment operator called" << std::endl;
	this->type = rhs.type;
	*(this->brain) = *(rhs.brain);
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << this->type << " makes : WoufWouf." << std::endl;
}