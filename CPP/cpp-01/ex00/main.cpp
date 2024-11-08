/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:48:16 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*		newZombie( std::string name );
void		randomChump( std::string name );

int main(int argc, char **argv)
{
	Zombie zombie ("Heinz (instance of Zombie created directly in Main on the Stack)");
	Zombie *newzombie;

	zombie.announce ();

	newzombie = newZombie ("New Zombie (Zombie created using the function newZombie with allocation dynamically in heap)");
	newzombie->announce ();

	randomChump("Chump (Zombie created in function randomChump on the Stack, only available inside this function)");

	(void) argc;
	(void) argv;
	delete newzombie;
	return (0);
}
