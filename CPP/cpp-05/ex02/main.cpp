/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 13:36:42 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void	try_and_catch (Bureaucrat &bureaucrat, AForm &formular)
{
	try
	{
		std::cout << "** Try to let Bureaucrate "  << bureaucrat << " sign and execute " << formular  << " **" << std::endl;
		bureaucrat.signForm(formular);
		bureaucrat.executeForm(formular);
//		std::cout << "*******" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	std::cout << std::endl;
	std::cout << "******* ShrubberyCreationForm test ****** " << std::endl;
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_a", 136);
		ShrubberyCreationForm form ("Targetname1");
		try_and_catch(b, form);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_b", 147);
		ShrubberyCreationForm form ("Targetname2");
		try_and_catch(b, form);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_c", 140);
		ShrubberyCreationForm form ("Targetname3");
		try_and_catch(b, form);
		
	}
	std::cout << std::endl;
	std::cout << "******* RobotomyRequestForm test ****** " << std::endl;
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_d", 45);
		RobotomyRequestForm form ("Targetname4");
		try_and_catch(b, form);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_e", 46);
		RobotomyRequestForm form ("Targetname5");
		try_and_catch(b, form);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_f", 73);
		RobotomyRequestForm form ("Targetname6");
		try_and_catch(b, form);
		
	}
	std::cout << std::endl;
	std::cout << "******* PresidentialPardonForm test ****** " << std::endl;
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_g", 5);
		PresidentialPardonForm form ("Targetname7");
		try_and_catch(b, form);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_h", 25);
		PresidentialPardonForm form ("Targetname8");
		try_and_catch(b, form);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_i", 26);
		PresidentialPardonForm form ("Targetname9");
		try_and_catch(b, form);
		
	}


	return 0;
}

