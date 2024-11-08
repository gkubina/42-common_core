/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 15:43:00 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal (void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Default_Animal";
}

Animal::Animal (Animal const & src)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	this->type = src.type;
}

Animal::~Animal (void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal " << this->type << " makes a default sound." << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}