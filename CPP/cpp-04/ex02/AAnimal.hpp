/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 17:58:27 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
	std::string type;
		
	public:
		AAnimal (void);
		AAnimal (AAnimal const & src);
		virtual ~AAnimal (void);

	AAnimal & operator=(AAnimal const & rhs);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;	
};

#endif
