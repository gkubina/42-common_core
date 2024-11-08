/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 11:40:36 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_HPP
# define GROUND_HPP
	
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ground : public ICharacter
{
	private:
		static const int size = 1024;		
		std::string	_name;
		AMateria	*_inventory[size];

		


	public:
		Ground(void);
		Ground(Ground const & src);
		~Ground(void);
	Ground & operator=(Ground const & rhs);

		Ground(std::string const & name);		

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		AMateria* getMateria(int idx) const;
};

#endif
