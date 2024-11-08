/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 12:28:10 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm (void) : AForm("RobotomyRequestForm", 72, 45, "default_target")
{
	std::cout << "Default RobotomyRequestForm constructor called : " << *this << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm (std::string const &target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called : " << *this << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm (RobotomyRequestForm const & src) : AForm(src)
{
	std::cout << "Copy RobotomyRequestForm constructor called : " << *this << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm (void)
{
	std::cout << "RobotomyRequestForm Destructor called : " << *this << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
    }
    std::cout << "RobotomyRequestForm assignment operator called : " << *this << std::endl;
    return *this;
}

void RobotomyRequestForm::action(void) const
{
	std::cout << "RobotomyRequestForm action called !" << std::endl;
    std::cout << "Making drilling noise !" << std::endl;
    srand (time(NULL));
    if ((std::rand() % 2))
    {
        std::cout << "Robotomy on " << this->getTarget() << " has been robotomized successfully !" <<  std::endl;        
    }
    else
    {
        std::cout << "Robotomy on " << this->getTarget() << " failed !" <<  std::endl;        
    }
}