/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:26:05 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 15:24:34 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//	In C++, when you declare a member variable as a reference 
//	(like Weapon& weapon), you must initialize it directly in the initializer 
//	list of the constructor. References must always be bound to a valid object 
//	when they are created, which is why you cannot assign to them inside the 
//	constructor body
HumanA::HumanA(const std::string& given_name, const Weapon& given_weapon) :
name(given_name), weapon(given_weapon)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()const
{
	std::cout << name << " attacks with " << weapon.getType() << std::endl;
}
