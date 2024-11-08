/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/02 15:28:08 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap (void)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
	this->_Name = "Default_ClapTrap";
	this->_HitPoints = 10;
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ClapTrap::ClapTrap (ClapTrap const & src)
{
	std::cout << "Copy ClapTrap constructor called" << std::endl;
	this->_Name = src._Name;
	this->_HitPoints = src._HitPoints;
	this->_AttackDamage = src._AttackDamage;
	this->_EnergyPoints = src._EnergyPoints;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ClapTrap::~ClapTrap (void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ClapTrap::ClapTrap (std::string name)
{
	std::cout << "ClapTrap constructor called with Name: " << name << std::endl;
	this->_Name = name;
	this->_HitPoints = 10;
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Copy ClapTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_HitPoints = rhs._HitPoints;
	this->_AttackDamage = rhs._AttackDamage;
	this->_EnergyPoints = rhs._EnergyPoints;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)
	{
		--this->_EnergyPoints;
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_AttackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " has not enough energy to attack " << target << "." <<std::endl;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_HitPoints = this->_HitPoints - amount;
	std::cout << "ClapTrap " << this->_Name << " was attacked, loosing " << amount << " Hitpoints!" << std::endl;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_EnergyPoints > 0 && this->_HitPoints > 0)	
	{
		--this->_EnergyPoints;
		this->_HitPoints = this->_HitPoints + amount;
		std::cout << "ClapTrap " << this->_Name << " repairs itself an gets " << amount << " Hitpoints back." << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " has not enough energy to repair itself." << std::endl;
	std::cout << "ClapTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}
