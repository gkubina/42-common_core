/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 15:46:25 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal (void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Default_Animal";
}

AAnimal::AAnimal (AAnimal const & src)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	this->type = src.type;
}

AAnimal::~AAnimal (void)
{
	std::cout << "Animal Destructor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

void AAnimal::makeSound(void) const
{
	std::cout << "Animal " << this->type << " makes a default sound." << std::endl;
}

std::string AAnimal::getType(void) const
{
	return this->type;
}