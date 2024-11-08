/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/19 16:45:59 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

void	try_and_catch (Bureaucrat &bureaucrat, Form &formular)
{
	try
	{
		std::cout << "** Try to let Bureaucrate "  << bureaucrat << " sign " << formular  << " **" << std::endl;
		bureaucrat.signForm(formular);
//		std::cout << "*******" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main()
{
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_b", 65);
		Form f("Form_f", 65, 35);
		try_and_catch(b, f);
		
	}
	{
		std::cout << "*******" << std::endl;
		Bureaucrat b("Bureaucrat_c", 75);
		Form f("Form_g", 65, 35);
		try_and_catch(b, f);
		
	}
	{
		std::cout << "*** Try Form with Signgrade out of range****" << std::endl;
	try 
		{
			Bureaucrat b("Bureaucrat_c", 75);
			Form f("Form_g", 151, 35);
			try_and_catch(b, f);
		}
	catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "*** Try Form with Executegrade out of range****" << std::endl;
		try 
		{
			Bureaucrat b("Bureaucrat_c", 75);
			Form f("Form_g", 35, 0);
			try_and_catch(b, f);
		}
		catch (std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

