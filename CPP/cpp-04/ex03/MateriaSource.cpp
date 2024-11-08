/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 13:44:29 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

	MateriaSource::MateriaSource(void)
	{
		std::cout << "Default Materiasource constructor called" << std::endl;
		for (size_t i = 0; i < this->size; i++)
		{
			this->_inventory[i] = NULL;
		}
	}

	MateriaSource::MateriaSource(MateriaSource const & src)
	{
		std::cout << "Copy MateriaSource constructor called" << std::endl;
		for (size_t i = 0; i < this->size; i++)
		{
			this->_inventory[i] = src.getMateria(i);
		}
	}

	MateriaSource::~MateriaSource(void)
	{
		std::cout << "Materiasource Destructor called" << std::endl; // to be compliant with the tests in the exercise, learned Materias in stock will be deleted.
		for (size_t i = 0; i < this->size; i++)
		{
			delete this->_inventory[i];
		}	
	}

	MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
	{
		std::cout << "Materiasource assignment operator called" << std::endl;
		for (size_t i = 0; i < this->size; i++)
		{
			delete this->_inventory[i];
			this->_inventory[i] = rhs.getMateria(i);
		}	
		return *this;
	}

	void MateriaSource::learnMateria(AMateria* m)
	{
		if (m == NULL)
		{
			std::cout << "Cannot learn NULL Materia!" << std::endl;
			return ;				
		}
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->_inventory[i] && this->_inventory[i]->getType() == m->getType())
				std::cout << "Materiasource already knows Materia " << m->getType() << " at index " << i << " !" << std::endl;
			else if (this->_inventory[i] == NULL)
			{
//				this->_inventory[i] = m->clone(); // Cloning Materia during learning process would be another logic, but would not comply to test in excercise.
				this->_inventory[i] = m;
				std::cout << "Materiasource learned Materia " << m->getType() << " at index " << i << " !" << std::endl;
				return ;
			}			
		}
		std::cout << "Materiasource cannot learn Materia " << m->getType() << " as stock is full." << std::endl;
	}

	AMateria* MateriaSource::createMateria(std::string const & type)
	{
		AMateria* ret = NULL;
		for (size_t i = 0; i < this->size; i++)
		{
			if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			{
				ret = this->_inventory[i]->clone();
				std::cout << "Materiasource created Materia " << ret->getType() << "." << std::endl;
				return (ret);
			}
		}
		std::cout << "Materiasource cannot create Materia " << type << "." << std::endl;
		return (ret);
	}

	AMateria* MateriaSource::getMateria(int idx) const
	{
		if (idx < 0 || idx >= this->size)
		{
			std::cout << "Materiasource cannot get Materia from idx out of range!" << std::endl;
			return (NULL);				
		}
		return (this->_inventory[idx]);
	}