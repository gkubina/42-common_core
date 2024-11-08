/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/01 12:09:18 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main()
{
//	const AAnimal* meta = new AAnimal(); // is not possible because AAnimal is pure virtual
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	const Cat* h = new Cat();
	const Cat* e = new Cat(*h);

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << h->getType() << " " << std::endl;
	std::cout << e->getType() << " " << std::endl;

	i->makeSound(); 
	j->makeSound();
	h->makeSound();
	e->makeSound();

	delete j;
	delete i;
	delete h;
	delete e;

	return 0;
}


/*
int main( void )
{
	AAnimal test; // will not compile as AAnimal is pure virtual

	return 0;
}
*/
