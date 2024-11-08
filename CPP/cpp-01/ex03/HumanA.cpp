/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:17 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:48:57 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA ()
{
	std::cout << "Debug message: " << this->_name << " died!" << std::endl;
	return ;
}

HumanA::HumanA (std::string name, Weapon &weapon) : _name (name), _weapon(weapon)
{
	std::cout << "Debug message: HumanA " << this->_name << " with weapon " << this->_weapon.getType() << " born!" << std::endl;
	return ;
}

void HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
	return ;
}

void	HumanA::attack ()
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	return ;
}

