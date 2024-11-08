/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 13:18:16 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat (void)
{
	std::cout << "Default WrongCat constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat (WrongCat const & src) : WrongAnimal(src)
{
	std::cout << "Copy WrongCat constructor called" << std::endl;
	this->type = src.type;
}

WrongCat::~WrongCat (void)
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	this->type = rhs.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << this->type << " makes : Miaou." << std::endl;
}