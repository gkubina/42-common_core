/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/01 12:06:19 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{

	std::cout << "Fill table with 3 Dogs and 3 Cats (Table of pointers to Animal)" << std::endl;
	{
	Animal *list[6];
	for (int i = 0; i < 3; i++)
	{
		list[i] = new Dog();
	}
	for (int i = 3; i < 6; i++)
	{
		list[i] = new Cat();
	}	
	std::cout << "Destroy 6 animals in table" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		delete list[i];
	}
	}

	std::cout << std::endl;
	std::cout << "Create 2 Cats and copy one to the other (Assigment operator)" << std::endl;
	{
		Cat i;
		Cat j;
		j = i;

		std::cout << std::endl;
		std::cout << "Create a new Cat from anther one (Copy constructor)" << std::endl;
		Cat k(j);
	}

	std::cout << std::endl;
	std::cout << "Create a new Dog from anther one (Assignement constructor)" << std::endl;
	{
		Dog basic;
		{
			Dog tmp = basic;
		}
	}

	std::cout << std::endl;
	std::cout << "Test from exercise" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
		
	}


	return 0;
}


