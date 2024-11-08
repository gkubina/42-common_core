/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/01 12:02:27 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat (void) : AAnimal() 
{
	std::cout << "Default Cat with Brain constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat (Cat const & src) : AAnimal(src)
{
	std::cout << "Copy Cat with Brain constructor called." << std::endl;
	this->type = src.type;
	this->brain = new Brain(*src.brain);
}

Cat::~Cat (void)
{
	std::cout << "Cat Destructor called." << std::endl;
	delete this->brain;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignment operator called." << std::endl;
	this->type = rhs.type;
	*(this->brain) = *(rhs.brain);
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << " makes : Miaou." << std::endl;
}