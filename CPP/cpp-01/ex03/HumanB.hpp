/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:10 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:49:02 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"


class HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		HumanB (std::string name);
		~HumanB (void);

		void setWeapon(Weapon &weapon);
		void attack ();
};

#endif
