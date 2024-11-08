/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/19 16:07:15 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
			int			_grade;
		
	public:
		Bureaucrat (void);
		Bureaucrat (Bureaucrat const & src);
		virtual ~Bureaucrat (void);		

		Bureaucrat (std::string const &name, int grade);

	Bureaucrat & operator=(Bureaucrat const & rhs);



		std::string getName() const;
		int getGrade() const;

		void incrementGrade(void);
		void decrementGrade(void);
		
		void signForm(Form &form);

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

std::ostream& operator<<(std::ostream & os, const Bureaucrat & rhs);

#endif
