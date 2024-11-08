/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 11:36:49 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ground.hpp"

Ground::Ground(void)
{
	std::cout << "Default Ground constructor called" << std::endl;
	this->_name = "Default_Name";
	for (size_t i = 0; i < this->size; i++)
	{
		this->_inventory[i] = NULL;
	}
}

Ground::Ground(Ground const & src)
{
	std::cout << "Copy Ground constructor called" << std::endl;
	this->_name = src.getName();
	for (size_t i = 0; i < this->size; i++)
	{
		this->_inventory[i] = src.getMateria(i)->clone();
	}
}

Ground::~Ground(void)
{
	std::cout << "Ground Destructor called" << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		delete this->_inventory[i];
	}	
}

AMateria* Ground::getMateria(int idx) const
{
	if (idx < 0 || idx >= this->size)
	{
		std::cout << this->_name << " cannot get Materia from idx out of range!" << std::endl;
		return (NULL);				
	}
	return (this->_inventory[idx]);
}

Ground & Ground::operator=(Ground const & rhs)
{
	std::cout << "Ground assignment operator called" << std::endl;
	this->_name = rhs.getName();
	for (size_t i = 0; i < this->size; i++)
	{
		delete this->_inventory[i];
		this->_inventory[i] = rhs.getMateria(i)->clone();
	}	
	return *this;
}

Ground::Ground(std::string const & name) : _name(name)
{
	std::cout << "Ground constructor called with name: " << name << "!" << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		this->_inventory[i] = NULL;
	}
}

std::string const & Ground::getName() const
{
	return(this->_name);
}

void Ground::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << this->_name << " cannot take over NULL Materia!" << std::endl;
		return ;				
	}
	for (size_t i = 0; i < this->size; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " took over Materia " << m->getType() << " at index " << i << " !" << std::endl;
			return ;
		}
	}
	std::cout << this->_name << " cannot take over Materia " << m->getType() << " as ground is full. Materia will be deleted!" << std::endl;
	delete m;
}

void Ground::unequip(int idx)
{
	if (idx < 0 || idx >= this->size)
	{
		std::cout << this->_name << " cannot give Materia from idx out of range!" << std::endl;
		return ;				
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << " cannot give Materia from idx " << idx << " as it is empty!" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
	std::cout << this->_name << " gave Materia " << " from index " << idx << " !" << std::endl;
}
void Ground::use(int idx, ICharacter& target)
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