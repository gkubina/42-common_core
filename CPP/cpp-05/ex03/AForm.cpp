/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 11:11:53 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm (void) : _name("Default_AForm_Name"), _grade_sign(150), _grade_exec(150), _signed(false), _target("Default_AForm_Target")
{
	std::cout << "Default AForm constructor called : " << *this << std::endl;
}

AForm::AForm (std::string const &name, int signgrade, int execgrade, std::string const &target) : _name(name), _grade_sign(signgrade), _grade_exec(execgrade), _signed(false), _target(target)
{
//	std::cout << "AForm constructor called : " << *this << std::endl;
	if (signgrade < 1 || execgrade < 1)
		throw (AForm::GradeTooHighException());
	if (signgrade > 150 || execgrade > 150)
		throw (AForm::GradeTooLowException());	
	std::cout << "AForm constructor called : " << *this << std::endl;
}

AForm::AForm (AForm const & src) : _name(src.getName()), _grade_sign(src.getSignGrade()), _grade_exec(src.getExecGrade()), _signed(src.getStatus()), _target(src.getTarget())
{
	std::cout << "Copy AForm constructor called : " << *this << std::endl;
}

AForm::~AForm (void)
{
	std::cout << "AForm Destructor called : " << *this << std::endl;
}

AForm & AForm::operator=(AForm const & rhs)
{
	this->_signed = rhs.getStatus();
	std::cout << "AForm assignment operator called : " << *this << std::endl;
	return *this;
}

std::string AForm::getName() const
{
	return (this->_name);
}

std::string AForm::getTarget() const
{
	return (this->_target);
}

int AForm::getSignGrade() const
{
	return (this->_grade_sign);
}

int AForm::getExecGrade() const
{
	return (this->_grade_exec);
}

bool AForm::getStatus() const
{
	return (this->_signed);
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
//	std::cout << bureaucrat << " signed " << *this << std::endl;
}

void AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (!this->_signed)
		throw (AForm::NotSignedException());
	if (bureaucrat.getGrade() > this->_grade_exec)
		throw (AForm::GradeTooLowException());
	this->action();
//	std::cout << bureaucrat << " executed " << *this << std::endl;
}

void AForm::action() const
{
	std::cout << "AForm action called : " << *this << std::endl;
}

const char* AForm::NotSignedException::what() const throw()
{
				return ("(AForm) Not signed exception !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
				return ("(AForm) Grade too low exception !");
}

const char* AForm::GradeTooHighException::what() const throw()
{
				return ("(AForm) Grade too high exception !");
}

std::ostream& operator<<(std::ostream & os, const AForm & rhs)
{
	if (rhs.getStatus())
		os << rhs.getName() << " with Target " << rhs.getTarget() << ", form sign grade " << rhs.getSignGrade() << ", form execution grade " << rhs.getExecGrade() << ", signed.";
	else
		os << rhs.getName() << " with Target " << rhs.getTarget() << ", form sign grade " << rhs.getSignGrade() << ", form execution grade " << rhs.getExecGrade() << ", not signed.";
	return (os);
}