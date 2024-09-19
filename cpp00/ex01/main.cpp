/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:27:44 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/19 14:39:23 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	PhoneBook	pbook;
	std::string	input;
	
	pbook.contact = -1;
	pbook.full_booked = 0;
    while (1)
    {
		signal(SIGQUIT, SIG_IGN);
        std::cout << "Hi, it's ur phonebook main page! Choose an option: (ADD / SEARCH / EXIT) \n";
		std::getline(std::cin, input);
		if (std::cin.eof())
			break;
		else if (input == "ADD")
			pbook.add_contact();
		else if (input == "SEARCH")
			pbook.search_contact();
		else if (input == "EXIT")
			break ;
    } 
    return (0);
}
