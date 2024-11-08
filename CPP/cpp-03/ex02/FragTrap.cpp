/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 10:57:23 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap (void)
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_Name = "Default_FragTrap";
	this->_HitPoints = 100;
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	std::cout << "FragTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

FragTrap::FragTrap (FragTrap const & src) : ClapTrap(src)
{
	
	std::cout << "Copy FragTrap constructor called" << std::endl;
	this->_Name = src._Name;
	this->_HitPoints = src._HitPoints;
	this->_AttackDamage = src._AttackDamage;
	this->_EnergyPoints = src._EnergyPoints;
	std::cout << "FragTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

FragTrap::~FragTrap (void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
	std::cout << "FragTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

FragTrap::FragTrap (std::string name)
{
	std::cout << "FragTrap constructor called with Name: " << name << std::endl;
	this->_Name = name;
	this->_HitPoints = 100;
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	std::cout << "FragTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "Copy FragTrap assignment operator called" << std::endl;
	this->_Name = rhs._Name;
	this->_HitPoints = rhs._HitPoints;
	this->_AttackDamage = rhs._AttackDamage;
	this->_EnergyPoints = rhs._EnergyPoints;
	std::cout << "FragTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_Name << " shows positive High Five Guys request." << std::endl;
	std::cout << "FragTrap_Status: Name: " << this->_Name << "; HitPoints: " << this->_HitPoints << "; AttackDamage: " << this->_AttackDamage << "; EnergyPoints: " << this->_EnergyPoints << std::endl;
}