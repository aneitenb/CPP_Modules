/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/18 10:36:02 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact index[8];
	public:
		PhoneBook();

		int			contact;
		void		add_contact();
		void		search_contact();
		void		create_new_contact(int i, std::string f, std::string l, std::string n, std::string p, std::string d);
		std::string	get_first_name(int i);
		std::string get_last_name(int i);
		std::string get_nickname(int i);
		std::string get_phone_number(int i);
		std::string get_darkest_secret(int i);
	
		~PhoneBook();
};

#endif