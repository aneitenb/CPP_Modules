/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/16 17:00:20 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "main.hpp"
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
	public:
		void		add_contact();
		void		search_contact();
		void		print_PhoneBook();
		std::string	truncate(std::string, size_t size);
};
#endif