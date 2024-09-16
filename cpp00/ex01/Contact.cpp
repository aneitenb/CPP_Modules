/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:41:19 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/16 17:15:33 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
	
}

Contact::~Contact(){
	
}

void	Contact::set_value(std::string f, std::string l, std::string n, std::string p, std::string s){
	first_name = f;
	last_name = l;
	nickname = n;
	phone_number = p;
	darkest_secret = s;
}

void	Contact::print_contact(void){
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nick name: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}

std::string	Contact::get_first_name(){
	return(first_name);
}

std::string	Contact::get_last_name(){
	return(last_name);
}

std::string	Contact::get_nickname(){
	return(nickname);
}

std::string	Contact::get_phone_number(){
	return(phone_number);
}

std::string	Contact::get_darkest_secret(){
	return(darkest_secret);
}
