/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:49:29 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl	harl;
	std::string message;

	if (argc == 2)
	{
		message = argv[1];
		harl.complain(message);
	}
	else
	{
		std::cout << "Please enter exactly 1 argument (WARNING, ERROR, INFO, DEBUG)" << std::endl;
		return (1);
	}
	return (0);
}
