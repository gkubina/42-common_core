/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/04 16:59:40 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
	Harl			harl;
	int				message = 4;
	const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	if (argc < 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}

	for (int i = 0; i < 4; i++)
	{
		if (argv[1] == levels[i])
			message = i;
	}

	switch (message)
	{
   		case 0:
				harl.complain("DEBUG");
				// fall through
   		case 1:
				harl.complain("INFO");
				// fall through
   		case 2:
				harl.complain("WARNING");
				// fall through
   		case 3:
				harl.complain("ERROR");
				break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}


