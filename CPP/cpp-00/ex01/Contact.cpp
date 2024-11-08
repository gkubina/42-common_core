/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:17 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:47:22 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact ()
{
	return ;
}

Contact::~Contact ()
{
	return ;
}

std::string Contact::Short (std::string field) const
{
	unsigned int stringsize;
	std::string	value;
	stringsize = field.size();
	value = field;
	if (stringsize > 10)
	{
		value.resize(9, ' ');
		value.resize(10, '.');
	}
	return (value);
}

void	Contact::Add(int index)
{
	this->firstname = "";
	this->lastname = "";
	this->nickname = "";
	this->phonenumber = "";
	this->secret = "";
	this->id = index + 1;
	while (this->firstname == "")
	{
		std::cout << std::endl <<"First Name? ";
		std::getline(std::cin, this->firstname);
	}
	while (this->lastname == "")
	{
		std::cout << std::endl <<"Last Name? ";
		std::getline(std::cin, this->lastname);
	}
	while (this->nickname == "")
	{
		std::cout << std::endl <<"Nickname? ";
		std::getline(std::cin, this->nickname);
	}
	while (this->phonenumber == "")
	{
		std::cout << std::endl <<"Phonenumber? ";
		std::getline(std::cin, this->phonenumber);
	}
	while (this->secret == "")
	{
		std::cout << std::endl <<"Darkest Secret? ";
		std::getline(std::cin, this->secret);
	}
}

void	Contact::Show() const
{
	std::cout.width(20);
	std::cout.fill(' ');
	std::cout << std::endl << std::left << "First Name : ";
	std::cout << this->firstname;

	std::cout.width(20);
	std::cout.fill(' ');
	std::cout << std::endl << std::left << "Last Name : ";
	std::cout << this->lastname;

	std::cout.width(20);
	std::cout.fill(' ');
	std::cout << std::endl << std::left << "Nickname : ";
	std::cout << this->nickname;

	std::cout.width(20);
	std::cout.fill(' ');
	std::cout << std::endl << std::left << "Phonenumber : ";
	std::cout << this->phonenumber;

	std::cout.width(20);
	std::cout.fill(' ');
	std::cout << std::endl << std::left << "Darkest Secret : ";
	std::cout << this->secret;

	std::cout << std::endl;
}

void	Contact::ShowIndex() const
{
	std::cout << "|";
	std::cout.width(10);
	std::cout.fill(' ');
	std::cout << std::right << this->id;
	std::cout << "|";
	std::cout.width(10);
	std::cout.fill(' ');
	std::cout << std::right << Short(this->firstname);
	std::cout << "|";
	std::cout.width(10);
	std::cout.fill(' ');
	std::cout << std::right << Short(this->lastname);
	std::cout << "|";
	std::cout.width(10);
	std::cout.fill(' ');
	std::cout << std::right << Short(this->nickname);
	std::cout << "|";
	std::cout << std::endl;
}
