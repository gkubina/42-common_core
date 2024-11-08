/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/09/04 16:11:19 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>

void ft_replace(std::ifstream *infile, std::ofstream *outfile, std::string s1, std::string s2)
{
	std::string::size_type	len_s1 (s1.length());
	std::string::size_type	len_s2 (s2.length());
	std::stringstream		buffer;
	std::string				input ("");
	std::string::size_type	found (0);

	buffer << infile->rdbuf();
	input = buffer.str();
	
	found = input.find(s1, found);
	while (found!=std::string::npos)
	{
		input.erase(found, len_s1);
		input.insert(found, s2);
		found = input.find(s1, found + len_s2);
	}
	if (outfile->good())
		*outfile << input;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "3 arguments needed (inputfile, s1, s2)" << std::endl;
		return (1);
	}
	std::ifstream			infile;
	std::ofstream			outfile;
	std::string				filename (argv[1]);
	std::string				s1(argv[2]);
	std::string				s2(argv[3]);
	std::string::size_type	len_s1 (s1.length());
	
	infile.open (filename.c_str(), std::ifstream::in);
	filename += ".replace";
	outfile.open (filename.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!infile.is_open() || !outfile.is_open() || len_s1 == 0)
	{
		std::cout << "File Problem or S1 not long enough. Output file might have been created anyway." << std::endl;
		infile.close();
		outfile.close();
		return (1);
	}
	ft_replace(&infile, &outfile, s1, s2);
	infile.close();
	outfile.close();
	return (0);
}

