/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 15:43:03 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat (void) : Animal() // : Animal() is the constructor of the parent class and optional to indicate here, if not indicated it is automatically added by the compiler
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat (Cat const & src) : Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->type = src.type;
}

Cat::~Cat (void)
{
	std::cout << "Cat Destructor called" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << this->type << " makes : Miaou." << std::endl;
}