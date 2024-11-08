/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/03 12:51:35 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
	
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		static const int size = 4;		
		AMateria	*_inventory[size];
	
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);
	MateriaSource & operator=(MateriaSource const & rhs);
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

	AMateria* getMateria(int idx) const;
};

#endif
