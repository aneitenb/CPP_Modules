/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:39:32 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 16:39:05 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "replace.hpp"

int	main(int ac, char **av)
{
	std::string	file;
	std::string	s1;
	std::string	s2;
	std::string	long_line;
	std::string	new_line;

	if (ac != 4)
	{
		std::cerr << "Error: Incorrect number of inputs, include <filename> \\
		<string to be replaced> <new string>" << std::endl;
		return (1);
	}
	file = av[1];
	s1 = av[2];
	s2 = av[3];
	
	std::ifstream inputFile(file);	//checks that the file can be opened
    if (!inputFile.is_open()) 
	{
        std::cerr << "Error: Could not open file " << file << std::endl;
        return (1);
	}
	
	std::ofstream outputFile(file + ".replace");	//opens output file
	if (!outputFile.is_open()) 
	{
        std::cerr << "Error: Could not create output file " << file << ".replace" << std::endl;
        return (1);
	}

	//	outputFile is an instance of std::ofstream (output file stream),
	//	which is used to write to a file. When you use outputFile with the 
	//	<< operator, it writes data to the file specified by the stream.
	while (std::getline(inputFile, long_line))
	{
        std::string new_line = replace_strings(long_line, s1, s2);
        outputFile << new_line << std::endl;
    }
	
}