/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:41:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/19 14:39:05 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){

}

PhoneBook::~PhoneBook(){

}

void	PhoneBook::add_contact()
{
	std::string first_name, last_name, nickname, phone_number, darkest_secret;
		
    std::cout << "First name:\n";
    std::getline(std::cin, first_name);
    if (std::cin.eof() || first_name.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
    std::cout << "Last name:\n";
    std::getline(std::cin, last_name);
    if (std::cin.eof() || last_name.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
    std::cout << "Nickname:\n";
    std::getline(std::cin, nickname);
    if (std::cin.eof() || nickname.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
    std::cout << "Phone number:\n";
    std::getline(std::cin, phone_number);
    if (std::cin.eof() || phone_number.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
    std::cout << "Contact's darkest_secret:\n";
    std::getline(std::cin, darkest_secret);
    if (std::cin.eof() || darkest_secret.length() < 1){
        std::cerr << "If you give me empty input, I'll send you back without saving<3\n";
        return ;
    }
	
	contact = (contact + 1) % 8;
	if (full_booked < 8)
		full_booked++;
	index[contact].set_value(first_name, last_name, nickname, phone_number, darkest_secret);
}

void		PhoneBook::search_contact()
{
	std::string	first_name, last_name, nickname;
    std::string	user_input;
    int			ui;

	if (full_booked == 0)
	{
		std::cout << "No contacts added yet!" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << " | " 
	<< std::setw(10) << "First Name" << " | " 
	<< std::setw(10) << "Last Name" << " | " 
	<< std::setw(10) << "Nickname" << std::endl;
	
	for (int i = 0; i < full_booked; i++)
	{
		first_name = index[i].get_first_name();
		last_name = index[i].get_last_name();
		nickname = index[i].get_nickname();
		
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
			
		std::cout << std::setw(10) << i + 1 << " | " 
		<< std::setw(10) << first_name << " | " 
		<< std::setw(10) << last_name << " | " 
		<< std::setw(10) << nickname << std::endl;
    }
	
	std::cout << std::endl;
	std::cout << "Choose a contact index to see more details:\n> ";
	std::getline(std::cin, user_input);
	if (std::cin.eof())
		return ;
	if (!std::isdigit(user_input[0]) || (user_input.size() > 1))
	{
		std::cout << "Index not found, sending you back to the main!\n";
		return;
	}
	ui = std::stoi(user_input);
	if (ui >= 1 && ui <= full_booked)
		index[ui - 1].print_contact();
	else
		std::cout << "Index not found, sending you back to the main!\n";
}