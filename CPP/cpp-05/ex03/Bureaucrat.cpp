/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 13:40:16 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat (void) : _name("Default_Bureaucrat_Name"), _grade(150)
{
	std::cout << "Default Bureaucrat constructor called : " << *this << std::endl;
}

Bureaucrat::Bureaucrat (std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());	
	std::cout << "Bureaucrat constructor called : " << *this << std::endl;
}

Bureaucrat::Bureaucrat (Bureaucrat const & src) : _name(src.getName()), _grade(src.getGrade())
{
	std::cout << "Copy Bureaucrat constructor called : " << *this << std::endl;
}

Bureaucrat::~Bureaucrat (void)
{
	std::cout << "Bureaucrat Destructor called : " << *this << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	this->_grade = rhs.getGrade();
	std::cout << "Bureaucrat assignment operator called : " << *this << std::endl;
	return *this;
}
		
std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
	std::cout << "Bureaucrat incremented : " << *this << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
	std::cout << "Bureaucrat decremented : " << *this << std::endl;
}

void Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << *this << " executed " << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
				return ("(B)Grade too high exception !");

}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
				return ("(B)Grade too low exception !");

}

std::ostream& operator<<(std::ostream & os, const Bureaucrat & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}