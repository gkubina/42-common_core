/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/17 16:40:18 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructor
// Canonical

ScalarConverter::ScalarConverter (void)
{
        std::cout << "Default ScalarConverter constructor called : " << std::endl;
}

ScalarConverter::ScalarConverter (ScalarConverter const & src)
{
        std::cout << "Copy ScalarConverter constructor called : " << std::endl;
        *this = src;
}

// Destructor
// Canonical
ScalarConverter::~ScalarConverter ()
{
        std::cout << "ScalarConverter Destructor called : " << std::endl;
}

// Assignment operator
// Canonical
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
        std::cout << "ScalarConverter assignment operator called : " << std::endl;
        if (this != &rhs) {
            // TODO: Assign member variables from rhs to this
        }
        return *this;
}

void printChar(char c)
{
    if (isprint(c))
    {
        std::cout << "char:    " << c << std::endl;
    }
    else
    {
        std::cout << "char:    Non displayable" << std::endl;
    }
}

void printInt(int i)
{
    std::cout << "int:     " << i << std::endl;
}

void printFloat(float f)
{
    std::cout << std::fixed << std::setprecision(1) << "float:   " << f << "f" << std::endl;
}

void printDouble(double d)
{
    std::cout << std::fixed << std::setprecision(1) << "double:  " << d << std::endl;
}

bool isValidDouble(const std::string& str) {
    //Check if the string is empty
    if (str.empty())
        return false;

    // Check for special cases
    if (str == "-inf" || str == "+inf" || str == "nan")
    {
        std::cout << "char:    impossible" << std::endl;
        std::cout << "int:     impossible" << std::endl;
        std::cout << "float:   " << str << "f" << std::endl;
        std::cout << "double:  " << str << std::endl;
        return true;   // Special case: "-inf", "+inf" or "nan"
    }

    // Check for decimal point
    if (str.find('.') == std::string::npos)
        return false; // No decimal point found

    std::istringstream iss(str);
    double value;

    // Attempt to read a double from the trimmed string
    iss >> value;

    // Check for a failed conversion
    if (iss.fail())
    {
        // std::cout << "Double Conversion failed." << std::endl;
        return false;
    }

    // Check for overflow/underflow
    if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max())
        return false; // Out of range for double

    // Check if we have consumed the entire input
    char c;
    if (iss >> c)
    {
        // If we read something after the double, return false
        // std::cout << "Extra characters detected: " << c << std::endl;
        return false;
    }

    // If we reached here, it means conversion was successful and no extra characters were found
    //std::cout << "Double Value : " << value << std::endl;

    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char:    impossible" << std::endl;
    else
        printChar(static_cast<char>(value));
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int:     impossible" << std::endl;
    else
        printInt(static_cast<int>(value));
    if (value < -std::numeric_limits<float>::max())
        std::cout << "float:   -inff" << std::endl;
    else if (value > std::numeric_limits<float>::max())
        std::cout << "float:   +inff" << std::endl;
    else
        printFloat(static_cast<float>(value));
    printDouble(value);
    return true;
}

bool isValidInt(const std::string& str) {
    //Check if the string is empty
    if (str.empty())
        return false;

    // Check for decimal point
    if (!(str.find('.') == std::string::npos))
        return false; // No decimal point should be found

    std::istringstream iss(str);
    int value;

    // Attempt to read a int from the string
    iss >> value;

    // Check for a failed conversion
    if (iss.fail())
    {
        // std::cout << "Int Conversion failed." << std::endl;
        return false;
    }

    // Check for overflow/underflow
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        return false; // Out of range for int
    
    // Check if we have consumed the entire input
    char c;
    if (iss >> c)
    {
        // If we read something after the int, return false
        // std::cout << "Extra characters detected: " << c << std::endl;
        return false;
    }

    // If we reached here, it means conversion was successful and no extra characters were found
    // std::cout << "Int Value : " << value << std::endl;
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char:    impossible" << std::endl;
    else
        printChar(static_cast<char>(value));
    printInt(value);
    printFloat(static_cast<float>(value));
    printDouble(static_cast<double>(value));
    return true;
}

bool isValidChar(const std::string& str) {
    //Check if the string is empty
    if (str.empty())
        return false;
    
    // Check for length
    if (str.size() != 1)
        return false; // Empty or longer than 1
    
    std::istringstream iss(str);
    char value;

    // Attempt to read a char from the string
    iss >> value;

    // Check for a failed conversion
    if (iss.fail())
    {
        // std::cout << "Char Conversion failed." << std::endl;
        return false;
    }
    
    if (isValidInt(str))
    {
        // std::cout << "Char is Int" << value << std::endl;
        return false;
    }

    // If we reached here, it means conversion was successful and no extra characters were found
   
    //std::cout << "Char Value : " << value << std::endl;
    printChar(value);
    printInt(static_cast<int>(value));
    printFloat(static_cast<float>(value));
    printDouble(static_cast<double>(value));
    return true;
}

bool isValidFloat(const std::string& str) {
    // Check is string is empty of missing the trailing 'f'
    if (str.empty() || str[str.size() - 1] != 'f')
        return false;

    // Check for special cases
    if (str == "-inff" || str == "+inff" || str == "nanf")
    {
        std::cout << "char:    impossible" << std::endl;
        std::cout << "int:     impossible" << std::endl;
        std::cout << "float:   " << str << std::endl;
        std::cout << "double:  " << str.substr(0, str.size() - 1) << std::endl;
        return true;   // Special case: "-inff" or "+inff" or "nanf"
    }

    // Remove the trailing 'f' for further checks
    std::string trimmedStr = str.substr(0, str.size() - 1);
    
    // Check for decimal point
    if (trimmedStr.find('.') == std::string::npos)
        return false; // No decimal point found

    std::istringstream iss(trimmedStr);
    float value;

    // Attempt to read a float from the trimmed string
    iss >> value;

    // Check for a failed conversion
    if (iss.fail())
    {
        // std::cout << "Conversion failed." << std::endl;
        return false;
    }

    if (!std::isfinite(value))
        return false; // Handle special case of inf and nan

    // Check for overflow/underflow
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
        return false; // Out of range for float
    
    // Check if we have consumed the entire input
    char c;
    if (iss >> c)
    {
        // If we read something after the float, return false
        // std::cout << "Extra characters detected: " << c << std::endl;
        return false;
    }

    // If we reached here, it means conversion was successful and no extra characters were found

    // std::cout << "Float Value : " << value << std::endl;
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char:    impossible" << std::endl;
    else
        printChar(static_cast<char>(value));
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int:     impossible" << std::endl;
    else
        printInt(static_cast<int>(value));
    printFloat(value);
    printDouble(static_cast<double>(value));
    return true;
}

void ScalarConverter::convert (std::string const & str)
{
//  std::cout << "Try to convert " << str << " to:" << std::endl;

    bool (*isValid[])(std::string const &str) = {&isValidDouble, &isValidFloat, &isValidInt, &isValidChar};	
	for (size_t i = 0; i < 4; i++)
	{
		if (isValid[i](str))
            return;
	}
    std::cout << "char:    impossible" << std::endl;
    std::cout << "int:     impossible" << std::endl;
    std::cout << "float:   impossible" <<  std::endl;
    std::cout << "double:  impossible" <<  std::endl;
}