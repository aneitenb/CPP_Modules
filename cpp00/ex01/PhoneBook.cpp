/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:41:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/18 10:31:14 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){

}

PhoneBook::~PhoneBook(){

}

void    PhoneBook::create_new_contact(int i, std::string f, std::string l, std::string n, std::string p, std::string d){
	index[i].set_value(f, l, n, p, d);
}

std::string PhoneBook::get_first_name(int i){
    return (index[i].get_first_name());
}

std::string PhoneBook::get_last_name(int i){
    return (index[i].get_last_name());
}

std::string PhoneBook::get_nickname(int i){
    return (index[i].get_nickname());
}

std::string PhoneBook::get_phone_number(int i){
    return (index[i].get_phone_number());
}

std::string PhoneBook::get_darkest_secret(int i){
    return (index[i].get_darkest_secret());
}
