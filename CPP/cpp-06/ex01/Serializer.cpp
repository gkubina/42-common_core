/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/22 10:53:00 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructor
// Canonical

Serializer::Serializer (void)
{
        std::cout << "Default Serializer constructor called : " << std::endl;
}

Serializer::Serializer (Serializer const & src)
{
        std::cout << "Copy Serializer constructor called : " << std::endl;
        *this = src;
}

// Destructor
// Canonical
Serializer::~Serializer ()
{
        std::cout << "Serializer Destructor called : " << std::endl;
}

// Assignment operator
// Canonical
Serializer & Serializer::operator=(Serializer const & rhs)
{
        std::cout << "Serializer assignment operator called : " << std::endl;
        if (this != &rhs) {
            // TODO: Assign member variables from rhs to this
        }
        return *this;
}

// Getters and Setters

// Other member functions

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}