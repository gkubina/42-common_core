/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 13:47:03 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Ground.hpp"
#include "MateriaSource.hpp"


int main()
{
	std::cout << "*** Create ground ***" << std::endl;
	Ground* ground = new Ground("GROUND");

	std::cout << "\n*** Create character ME + 5 Materia and try to equip ME with 4 + 1 Materia ***" << std::endl;
	Character* me = new Character("ME");
	AMateria* mat1 = new Ice();
	me->equip(mat1);
	AMateria* mat2 = new Cure();
	me->equip(mat2);	
	AMateria* mat3 = new Ice();
	me->equip(mat3);
	AMateria* mat4 = new Cure();
	me->equip(mat4);	
	AMateria* mat5 = new Cure();
	me->equip(mat5);

	std::cout << "\n*** Create second character YOU and try to use different Materia ***" << std::endl;

	Character* you = new Character("YOU");
	me->use(0, *you);
	me->use(1, *you);
	me->use(2, *you);
	me->use(3, *you);
	me->use(4, *you);
	me->use(5, *you);
	you->use(0, *you);
	you->use(1, *you);
	me->use(0, *you);
	me->use(1, *you);

	std::cout << "\n*** Let ME unequip Materia, the Ground will take it over ***" << std::endl;

	for (size_t i = 0; i < 4; i++)
	{
		ground->equip(me->getMateria(i));
		me->unequip(i);
	}

	std::cout << "\n*** Let ME equip Materia from the Ground ***" << std::endl;

	you->equip(ground->getMateria(0));
	ground->unequip(0);
	

	std::cout << "\n*** Let ME try to unequip Materia that he does not have ***" << std::endl;
	me->unequip(2);
	me->unequip(0);
	
	std::cout << "\n*** Delete ME / YOU and the GROUND try to unequip Materia that he does not have ***" << std::endl;
	delete you;
	delete me;
	delete ground;

	std::cout << "\n*** Materiasource Tests ***" << std::endl;
	{

		IMateriaSource* src = new MateriaSource();
		AMateria* tmp = new Ice();
		AMateria* tmp2 = new Ice();
		src->learnMateria(tmp);
		src->learnMateria(tmp2);
		AMateria* tmp3 = src->createMateria("ice");
		AMateria* tmp4 = src->createMateria("cure");

		delete src;
		delete tmp3;
		delete tmp4;

	}


	std::cout << "\n*** Tests from excercise for Materiasource ***" << std::endl;
	{

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;

	}

	return 0;
}