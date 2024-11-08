/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/23 18:36:12 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	
	private:
		virtual void action(void) const;
	
	public:
		ShrubberyCreationForm (void);
		ShrubberyCreationForm (ShrubberyCreationForm const & src);
		virtual ~ShrubberyCreationForm (void);		

		ShrubberyCreationForm (std::string const &target);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);		
};

#endif
