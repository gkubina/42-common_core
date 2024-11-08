/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 15:42:05 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog (void)
{
	std::cout << "Default Dog with Brain constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain;
}

Dog::Dog (Dog const & src) : Animal(src)
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