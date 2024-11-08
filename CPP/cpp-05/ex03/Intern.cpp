/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 17:11:55 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern (void) 
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern (Intern const & src)
{
	(void) src;
	std::cout << "Copy Intern constructor called" << std::endl;
}

Intern::~Intern (void)
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void) rhs;
	std::cout << "Intern assignment operator called" << std::endl;
	return *this;
}

AForm* PForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* RForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* SForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string const &form, std::string const &target)
{
	AForm *(*form_func[])(std::string const &target) = {&PForm, &RForm, &SForm};
	std::string form_name[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (size_t i = 0; i < 3; i++)
	{
		if (form == form_name[i])
		{
			std::cout << "Intern creates " << form_name[i] << std::endl;
			return (form_func[i](target));
		}
	}	
	std::cout << "Intern cannot create: " << form << "as it does not exist." << std::endl;
	return (NULL);

}

