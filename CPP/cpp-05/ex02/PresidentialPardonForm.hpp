/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 13:29:20 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
	
	private:
		virtual void action(void) const;
	
	public:
		PresidentialPardonForm (void);
		PresidentialPardonForm (PresidentialPardonForm const & src);
		virtual ~PresidentialPardonForm (void);		

		PresidentialPardonForm (std::string const &target);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);		
};

#endif
