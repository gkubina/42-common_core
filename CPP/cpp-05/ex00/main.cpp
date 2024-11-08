/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/13 12:48:21 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

void	try_and_catch (std::string name, int grade)
{
	try
	{
		std::cout << "** Try to create a Bureaucrate "  << name << " with grade " << grade << " and in- and decrement it **" << std::endl;
		Bureaucrat b (name, grade);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	try_and_catch("Bureaucrat_65", 65);
	try_and_catch("Bureaucrat_1", 1);
	try_and_catch("Bureaucrat_150", 150);
	try_and_catch("Bureaucrat_0", 0);
	try_and_catch("Bureaucrat_151", 151);
	try_and_catch("Bureaucrat_-1", -1);
	{
		std::cout << "** Other tests **" << std::endl;

		Bureaucrat b("Bureaucrat_B", 1);
		std::cout << b << std::endl;
		Bureaucrat c("Bureaucrat_C", 150);
		std::cout << c << std::endl;
		Bureaucrat d(b);
		std::cout << d << std::endl;
		c = b;
		std::cout << c << std::endl;
	}
	{
		std::cout << "** Test with pointer and new **" << std::endl;

		Bureaucrat *e = NULL;
		try
		{
			e = new Bureaucrat("Bureaucrat_E", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n'; // no need to delete, as the object is not created (runtime does the cleanup )
		}
		(void)e;
		delete e;
	}
	return 0;
}

