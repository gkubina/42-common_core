/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 17:12:39 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm* form;
	form = someRandomIntern.makeForm("PresidentialPardonForm", "Tar1");
	delete form;
	form = someRandomIntern.makeForm("ShrubberyCreationForm", "Tar2");
	delete form;
	form = someRandomIntern.makeForm("RobotomyRequestForm", "Tar3");
	delete form;
	form = someRandomIntern.makeForm("RequestForm", "Tar4");
	delete form;
	return 0;
}
