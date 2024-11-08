/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 15:41:56 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat (void) : Animal() 
{
	std::cout << "Default Cat with Brain constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain;
}

Cat::Cat (Cat const & src) : Animal(src)
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