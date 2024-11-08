/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:10 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:47:36 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <sstream>
# include "Contact.hpp"

class PhoneBook
{
	private:
		unsigned int	fillsize;
		unsigned int	newest_contact;

		Contact Book[8];

		void ShowContact (unsigned index) const;
		void AddContact ();
		void SearchContact () const;
		void Contactlist () const;

	public:
		PhoneBook (void);
		~PhoneBook (void);

		void Menu ();
};

#endif
