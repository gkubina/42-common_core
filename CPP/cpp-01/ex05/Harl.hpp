/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:10 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:49:27 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>
# include <string>

class Harl
{
	private:
		void	debug (void) const;
		void	info (void) const;
		void	warning (void) const;
		void	error (void) const;

		typedef void(Harl::*HarlMemberFunction)() const;
		int		getLevel(std::string level);


	public:
			Harl (void);
			~Harl (void);
		void complain (std::string level);
};




#endif
