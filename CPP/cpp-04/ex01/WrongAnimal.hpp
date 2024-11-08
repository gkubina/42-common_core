/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 13:33:38 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
	std::string type;
		
	public:
		WrongAnimal (void);
		WrongAnimal (WrongAnimal const & src);
		~WrongAnimal (void);		

	WrongAnimal & operator=(WrongAnimal const & rhs);

	void makeSound(void) const;
	std::string getType(void) const;	
};

#endif
