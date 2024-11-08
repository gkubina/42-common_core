/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/19 16:06:53 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
			int	const		_grade_sign;
			int	const		_grade_exec;
			bool			_signed;
		
	public:
		Form (void);
		Form (Form const & src);
		virtual ~Form (void);		

		Form (std::string const &name, int signgrade, int execgrade);

	Form & operator=(Form const & rhs);

		std::string getName() const;
		int getExecGrade() const;
		int getSignGrade() const;
		bool getStatus() const;

		void beSigned(Bureaucrat const & bureaucrat);
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};


};

std::ostream& operator<<(std::ostream & os, const Form & rhs);

#endif
