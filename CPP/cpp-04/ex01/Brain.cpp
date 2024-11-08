/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/30 15:30:41 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain (void)
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i]="Single Great Idea";
//		std::cout << this->ideas[i] << std::endl;
	}
	std::cout << "Brain created and filled with 100 ideas." << std::endl;	
}

Brain::Brain (Brain & src)
{
	this->ideas = new std::string[100];
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i]=src.get_ideas()[i];
	}
	std::cout << "New Brain created and filled with 100 deep copied ideas." << std::endl;	
}

Brain::~Brain (void)
{
	delete[] this->ideas;
	std::cout << "Brain destroyed." << std::endl;
}

Brain & Brain::operator=(Brain & rhs)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i]=rhs.get_ideas()[i];
//		std::cout << this->ideas[i] << std::endl;
	}
	std::cout << "100 Ideas copied by copy assignment operator." << std::endl;
	return *this;
}

std::string*  Brain::get_ideas(void)
{
	return (this->ideas);
}
