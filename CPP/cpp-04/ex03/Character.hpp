/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 12:44:47 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
	
// # include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		static const int size = 4;		
		std::string	_name;
		AMateria	*_inventory[size];

	public:
		Character(void);
		Character(Character const & src);
		~Character(void);
	Character & operator=(Character const & rhs);

		Character(std::string const & name);		

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria* getMateria(int idx) const;
};

#endif
