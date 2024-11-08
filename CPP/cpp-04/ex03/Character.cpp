/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 12:24:41 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(void)
{
	std::cout << "Default Character constructor called" << std::endl;
	this->_name = "Default_Name";
	for (size_t i = 0; i < this->size; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Character::Character(Character const & src)
{
	std::cout << "Copy Character constructor called" << std::endl;
	this->_name = src.getName();
	for (size_t i = 0; i < this->size; i++)
	{
		this->_inventory[i] = src.getMateria(i)->clone();
	}
}

Character::~Character(void)
{
	std::cout << "Character Destructor called" << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		delete this->_inventory[i];
	}	
}

AMateria* Character::getMateria(int idx) const
{
	if (idx < 0 || idx >= this->size)
	{
		std::cout << this->_name << " cannot get Materia from idx out of range!" << std::endl;
		return (NULL);				
	}
	return (this->_inventory[idx]);
}

Character & Character::operator=(Character const & rhs)
{
	std::cout << "Character assignment operator called" << std::endl;
	this->_name = rhs.getName();
	for (size_t i = 0; i < this->size; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = rhs.getMateria(i)->clone();
	}	
	return *this;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character constructor called with name: " << name << "!" << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		this->_inventory[i] = NULL;
	}
}

std::string const & Character::getName() const
{
	return(this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << this->_name << " cannot equip NULL Materia!" << std::endl;
		return ;				
	}
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped Materia " << m->getType() << " at index " << i << " !" << std::endl;
			return ;
		}
	}
	std::cout << this->_name << " cannot equip Materia " << m->getType() << " as stock is full. Materia will be deleted!" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= this->size)
	{
		std::cout << this->_name << " cannot unequip Materia from idx out of range!" << std::endl;
		return ;				
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " cannot unequip Materia from idx " << idx << " as it is empty!" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << this->_name << " unequipped Materia from index " << idx << " !" << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= this->size)
	{
		std::cout << this->_name << " cannot use Materia from idx out of range!" << std::endl;
		return ;				
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " cannot use Materia from idx " << idx << " as it is empty!" << std::endl;
		return ;
	}
	std::cout << this->_name << " will now use Materia " << this->_inventory[idx]->getType() << " from index " << idx << " on Target: " << target.getName() << std::endl;
	this->_inventory[idx]->use(target);
}