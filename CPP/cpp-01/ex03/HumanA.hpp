/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:10 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:48:58 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"


class HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA (std::string name, Weapon &weapon);
		~HumanA (void);

		void setWeapon(Weapon weapon);
		void attack ();
};

#endif
