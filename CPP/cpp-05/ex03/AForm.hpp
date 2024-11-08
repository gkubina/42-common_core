/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/23 16:42:27 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
			int	const		_grade_sign;
			int	const		_grade_exec;
			bool			_signed;
		std::string const	_target;
				
		virtual void action() const = 0; // pure virtual function

	public:
		AForm (void);
		AForm (AForm const & src);
		virtual ~AForm (void);		

		AForm (std::string const &name, int signgrade, int execgrade, std::string const & target);

	AForm & operator=(AForm const & rhs);

		std::string getName() const;
		int getExecGrade() const;
		int getSignGrade() const;
		bool getStatus() const;
		std::string getTarget() const;

		void beSigned(Bureaucrat const & bureaucrat);
		
		virtual void execute(Bureaucrat const & executor) const;
		
	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

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

std::ostream& operator<<(std::ostream & os, const AForm & rhs);

#endif
