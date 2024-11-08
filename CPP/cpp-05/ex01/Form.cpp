/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/19 16:49:14 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form (void) : _name("Default_Form_Name"), _grade_sign(150), _grade_exec(150), _signed(false)
{
	std::cout << "Default Form constructor called : " << *this << std::endl;
}

Form::Form (std::string const &name, int signgrade, int execgrade) : _name(name), _grade_sign(signgrade), _grade_exec(execgrade), _signed(false)
{
//	std::cout << "Form constructor called : " << *this << std::endl;
	if (signgrade < 1 || execgrade < 1)
		throw (Form::GradeTooHighException());
	if (signgrade > 150 || execgrade > 150)
		throw (Form::GradeTooLowException());	
	std::cout << "Form constructor called : " << *this << std::endl;
}

Form::Form (Form const & src) : _name(src.getName()), _grade_sign(src.getSignGrade()), _grade_exec(src.getExecGrade()), _signed(src.getStatus())
{
	std::cout << "Copy Form constructor called : " << *this << std::endl;
}

Form::~Form (void)
{
	std::cout << "Form Destructor called : " << *this << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
	this->_signed = rhs.getStatus();
	std::cout << "Form assignment operator called : " << *this << std::endl;
	return *this;
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getSignGrade() const
{
	return (this->_grade_sign);
}

int Form::getExecGrade() const
{
	return (this->_grade_exec);
}

bool Form::getStatus() const
{
	return (this->_signed);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_sign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
//	std::cout << bureaucrat << " signed " << *this << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
				return ("(Form)Grade too high exception !");

}

const char* Form::GradeTooLowException::what() const throw()
{
				return ("(Form)Grade too low exception !");

}

std::ostream& operator<<(std::ostream & os, const Form & rhs)
{
	if (rhs.getStatus())
		os << rhs.getName() << ", form sign grade " << rhs.getSignGrade() << ", form execution grade " << rhs.getExecGrade() << ", signed.";
	else
		os << rhs.getName() << ", form sign grade " << rhs.getSignGrade() << ", form execution grade " << rhs.getExecGrade() << ", not signed.";
	return (os);
}