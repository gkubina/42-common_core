/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:17 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:47:29 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook ()
{
	this->fillsize = 0;
	this->newest_contact = 7;
}

PhoneBook::~PhoneBook ()
{
	return ;
}

void PhoneBook::AddContact (void)
{
	unsigned id;

	if (this->fillsize < 8)
		this->fillsize++;
	if (this->newest_contact == 7)
		id = 0;
	else
		id = this->newest_contact + 1;
	Book[id].Add(id);
	this->newest_contact = id;
}

void PhoneBook::Contactlist (void) const
{
	unsigned i;

	i = 0;
	while (i < this->fillsize)
	{
		Book[i].ShowIndex ();
		i++;
	}
}

void PhoneBook::ShowContact (unsigned index) const
{
	Book[index].Show ();
}

void PhoneBook::Menu (void)
{
	std::string command;

	command = "";
	std::cout << std::endl << "*** Welcome to the '80s Phonebook ***" << std::endl;
	while (command == "")
	{
		std::cout << std::endl << "Command (ADD, SEARCH or EXIT)? ";
		std::getline(std::cin, command);
		if (command == "ADD")
			AddContact ();
		else if (command == "SEARCH")
			SearchContact ();
		else if (command == "EXIT")
			return ;
		command = "";
	}
}

void PhoneBook::SearchContact (void) const
{
	std::string input;
	unsigned id;

	id = this->fillsize + 1;
	input = "";
	if (this->fillsize == 0)
	{
		std::cout << std::endl << "Phonebook is empty." << std::endl;
		return ;
	}
	std::cout << std::endl << "*** Contact List ***" << std::endl << std::endl;
	Contactlist ();
	while (id < 1 || id > this->fillsize)
	{
		std::cout << std::endl << "Index of Contact to show? ";
		std::getline(std::cin, input);
		std::stringstream(input) >> id;
		input = "";
	}
	ShowContact(id - 1);
}

