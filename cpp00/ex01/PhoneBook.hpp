/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:50:55 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/18 19:07:38 by aneitenb         ###   ########.fr       */
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
		int			full_booked;
		void		add_contact();
		void		search_contact();
	
		~PhoneBook();
};

#endif