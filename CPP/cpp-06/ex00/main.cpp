/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/17 16:01:50 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"


int main(const int argc, const char **argv)
{
	// ScalarConverter x; not possible to instanciate
	
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
