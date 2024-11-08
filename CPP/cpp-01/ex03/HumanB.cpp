/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:17 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/04 15:42:07 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB ()
{
	std::cout << "Debug message: " << this->_name << " died!" << std::endl;
	return ;
}

HumanB::HumanB (std::string name) : _name (name), _weapon(NULL)
{
	std::cout << "Debug message: HumanB " << this->_name << " without weapon born!" << std::endl;
	return ;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

void	HumanB::attack ()
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}

