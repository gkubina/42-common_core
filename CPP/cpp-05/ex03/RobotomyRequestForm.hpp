/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 12:30:25 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	
	private:
		virtual void action(void) const;
	
	public:
		RobotomyRequestForm (void);
		RobotomyRequestForm (RobotomyRequestForm const & src);
		virtual ~RobotomyRequestForm (void);		

		RobotomyRequestForm (std::string const &target);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);		
};

#endif
