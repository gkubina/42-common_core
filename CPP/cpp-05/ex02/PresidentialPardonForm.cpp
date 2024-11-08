/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 13:31:13 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm (void) : AForm("PresidentialPardonForm", 25, 5, "default_target")
{
	std::cout << "Default PresidentialPardonForm constructor called : " << *this << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm (std::string const &target) : AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called : " << *this << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm (PresidentialPardonForm const & src) : AForm(src)
{
	std::cout << "Copy PresidentialPardonForm constructor called : " << *this << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm (void)
{
	std::cout << "PresidentialPardonForm Destructor called : " << *this << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    std::cout << "PresidentialPardonForm assignment operator called : " << *this << std::endl;
    return *this;
}

void PresidentialPardonForm::action(void) const
{
	std::cout << "PresidentialPardonForm action called !" << std::endl;
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." <<  std::endl;        
}