/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/17 13:54:27 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter {
    
    private:  
    // Constructor
        ScalarConverter(void); // Canonical
        ScalarConverter (ScalarConverter const & src); // Canonical

    // Destructor
        virtual ~ScalarConverter(); // Canonical
    
    // Assignement operator 
    ScalarConverter & operator=(ScalarConverter const & rhs); // Canonical
    
    public:
    // Other member functions
    static void convert (std::string const & str);

};

