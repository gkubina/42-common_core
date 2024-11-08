/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 13:12:54 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
	Zombie	*horde;
	if (argc == 3)
	{
		horde = zombieHorde(std::atoi (argv[1]), argv[2]);

		for (int i=0; i < std::atoi (argv[1]); i++)
			horde[i].announce ();
	}
	else
	{
		std::cout << "Please enter as arguments the no of Zombies and a Name" << std::endl;
		return (1);
	}
	delete [] horde;
	return (0);
}
