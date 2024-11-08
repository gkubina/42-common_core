/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/22 10:44:54 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>  // Include any necessary standard libraries
# include <cstddef>
# include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer {
        private:
        // Member variables

        // Constructor
                Serializer(); // Canonical
                Serializer (Serializer const & src); // Canonical

        // Destructor
                ~Serializer(); // Canonical

        // Assignement operator 
        Serializer & operator=(Serializer const & rhs); // Canonical

        // Getters and Setters

        // Other member functions
        
        public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};

#endif // SERIALIZER_HPP