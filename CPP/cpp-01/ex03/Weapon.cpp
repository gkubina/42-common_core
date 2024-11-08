/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:17 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:49:11 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon (std::string type) : _type(type)
{
	std::cout << "Debug message: " << this->_type << " created!" << std::endl;
	return ;
}

Weapon::~Weapon (void)
{
	std::cout << "Debug message: " << this->_type << " destroyed!" << std::endl;
	return ;
}

void	Weapon::setType (std::string type)
{
	this->_type = type;
	std::cout << "Debug message: " << this->_type << " modified!" << std::endl;
	return ;
}

std::string const &	Weapon::getType() const
{
	return (this->_type);
}
