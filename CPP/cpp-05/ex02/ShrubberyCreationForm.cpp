/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 13:35:03 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm (void) : AForm("ShrubberyCreationForm", 145, 137, "default_target")
{
	std::cout << "Default ShrubberyCreationForm constructor called : " << *this << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm (std::string const &target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called : " << *this << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm (ShrubberyCreationForm const & src) : AForm(src)
{
	std::cout << "Copy ShrubberyCreationForm constructor called : " << *this << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm (void)
{
	std::cout << "ShrubberyCreationForm Destructor called : " << *this << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    std::cout << "ShrubberyCreationForm assignment operator called : " << *this << std::endl;
    return *this;
}

void ShrubberyCreationForm::action(void) const
{
	std::cout << "ShrubberyCreationForm action called !" << std::endl;
    std::ofstream outfile((this->getTarget() + "_shrubbery").c_str(), std::ofstream::app);
    std::string ascii_tree =
        "    *\n"
        "   ***\n"
        "  *****\n"
        "   ***\n"
        "    *\n"
        "   |||\n"
        "   |||\n"
        "\n";
    if (outfile.is_open())
    {
        outfile << ascii_tree;
        outfile.close();
        std::cout << "ASCII written to " << (this->getTarget() + "_shrubbery !") << std::endl;
    }
    else
    {
        std::cerr << "Error opening " << (this->getTarget() + "_shrubbery") << " for writing!" << std::endl;
    }
}