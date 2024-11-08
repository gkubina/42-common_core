/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 10:32:54 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap (void)
{
	std::cout << "Default ScavTrap constructor called" << std::endl;
	this->_Name = "Default_ScavTrap";
	this->_HitPoints = 100;
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ScavTrap::ScavTrap (ScavTrap const & src) : ClapTrap(src)
{
	
	std::cout << "Copy ScavTrap constructor called" << std::endl;
	this->_Name = src._Name;
	this->_HitPoints = src._HitPoints;
	this->_AttackDamage = src._AttackDamage;
	this->_EnergyPoints = src._EnergyPoints;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ScavTrap::~ScavTrap (void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ScavTrap::ScavTrap (std::string name)
{
	std::cout << "ScavTrap constructor called with Name: " << name << std::endl;
	this->_Name = name;
	this->_HitPoints = 100;
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	std::cout << "Copy ScavTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_HitPoints = rhs._HitPoints;
	this->_AttackDamage = rhs._AttackDamage;
	this->_EnergyPoints = rhs._EnergyPoints;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		--this->_EnergyPoints;
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_Name << " has not enough energy to attack " << target << "." <<std::endl;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_Name << " is now in Gatekeeper mode." << std::endl;
	std::cout << "ScavTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}