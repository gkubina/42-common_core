/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/01 10:46:19 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	const Cat* h = new Cat();
	const Cat* e = new Cat(*h);

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << h->getType() << " " << std::endl;
	std::cout << e->getType() << " " << std::endl;

	i->makeSound(); 
	j->makeSound();
	meta->makeSound();

	h->makeSound();
	e->makeSound();
	

	delete meta;
	delete j;
	delete i;
	delete h;
	delete e;

	std::cout << "\nWrong Animal/Wrong Cat\n" << std::endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound(); 
	meta2->makeSound();
	WrongCat l;
	std::cout << l.getType() << " " << std::endl;
	l.makeSound();

	delete meta2;
	delete k;

	return 0;
}



