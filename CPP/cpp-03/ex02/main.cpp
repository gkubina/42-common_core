/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/03 10:46:57 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main( void )
{
	FragTrap a ("AAA");
	FragTrap b;

	a.attack("another one");
	a.takeDamage(5);
	b = a;
	b.beRepaired(14);
	FragTrap c(b);
	c.highFivesGuys();

	return 0;
}

