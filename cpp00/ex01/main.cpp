/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:27:44 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/18 11:58:06 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	PhoneBook::add_contact()
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
	
    std::cout << "First name:\n ";
    std::getline(std::cin, first_name);
    if (std::cin.eof() || first_name.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }

    std::cout << "Last name:\n ";
    std::getline(std::cin, last_name);
    if (std::cin.eof() || last_name.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }

    std::cout << "Nickname:\n ";
    std::getline(std::cin, nickname);
    if (std::cin.eof() || nickname.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
   
    std::cout << "Phone number:\n ";
    std::getline(std::cin, phone_number);
    if (std::cin.eof() || phone_number.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }

    std::cout << "Contact's darkest_secret\n ";
    std::getline(std::cin, darkest_secret);
    if (std::cin.eof() || darkest_secret.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
	
	if (contact == 0 || contact >= 8)
        contact = 1;
	else
		contact++;
	create_new_contact(this->contact, first_name, last_name, nickname, phone_number, darkest_secret);
}

void		PhoneBook::search_contact()
{
	std::string	first_name, last_name, nickname;
    std::string	user_input;
    int			ui;

	if (contact == 0)
	{
		std::cout << "No contacts added yet!" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << std::setw(12) << "Index" << " | " 
	<< std::setw(12) << "First Name" << " | " 
	<< std::setw(12) << "Last Name" << " | " 
	<< std::setw(12) << "Nickname" << std::endl;
	
	for (int i = 0; i < contact; ++i)
	{
		first_name = get_first_name(i + 1);
		last_name = get_last_name(i + 1);
		nickname = get_nickname(i + 1);
		
		if (first_name.length() > 12)
			first_name = first_name.substr(0, 11) + ".";
		if (last_name.length() > 12)
			last_name = last_name.substr(0, 11) + ".";
		if (nickname.length() > 12)
			nickname = nickname.substr(0, 11) + ".";
			
		std::cout << std::setw(12) << i + 1 << " | " 
		<< std::setw(12) << first_name << " | " 
		<< std::setw(12) << last_name << " | " 
		<< std::setw(12) << nickname << std::endl;
    }
	
		std::cout << std::endl;
		std::cout << "Enter the contact's index to see more details:\n> ";
		std::getline(std::cin, user_input);
		if (std::cin.eof())
			return ;
		if (!std::isdigit(user_input[0]) || (user_input.size() > 1))
		{
			std::cout << "Wrong index, sending you back to the main!\n";
			return;
		}
		ui = std::stoi(user_input);
		if (ui >= 1 && ui <= contact)
			index[ui].print_contact();
		else
			std::cout << "Wrong index, sending you back to the main!\n";
}

int main(void)
{
	PhoneBook	pbook;
	std::string	input;
	
	pbook.contact = 0;
    while (1)
    {
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

