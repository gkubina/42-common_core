/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:19:10 by gkubina           #+#    #+#             */
/*   Updated: 2024/06/25 11:47:25 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
	private:
		int	id;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phonenumber;
		std::string	secret;

		std::string Short(std::string) const;

	public:
		Contact (void);
		~Contact (void);

		void Add (int index);
		void Show (void) const;
		void ShowIndex (void) const;
};

#endif
