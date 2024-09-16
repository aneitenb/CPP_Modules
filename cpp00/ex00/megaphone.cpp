/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:44:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/16 12:20:00 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	//reads or writes to the standard input/output streams
#include <cstring>	//for strlen
#include <cctype>	//for toupper

int main(int ac, char **av)
{
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			//note: toupper returns int, so it must be cast as char
			for (size_t j = 0; j < std::strlen(av[i]); j++)
				std::cout << (char)std::toupper(av[i][j]);
		}
		std::cout << std::endl;	//adds a newline after everything has printed
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
