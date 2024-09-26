/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:45:07 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 14:52:59 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

# define WEAPON_HPP
# include <string>
# include <iostream>

//	The const keyword ensures that the caller cannot modify the string 
//	returned by the functions, protecting the integrity of the Weapon class's 
//	internal state.
//
//	When you pass a string by value (i.e., std::string type), a copy of the 
//	string is created. This involves allocating memory for the new string and 
//	copying the content, which can be inefficient, especially for larger strings.
//	This is why I use a reference to the string: to save copying the string and
//	to be faster.
class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(const std::string& given_type);
		~Weapon();
		
		const std::string& getType() const;
		void setType(const std::string& given_type);
};

#endif