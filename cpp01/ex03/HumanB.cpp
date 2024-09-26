/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:25:49 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 15:19:28 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& given_name): weapon(NULL)
{
	name = given_name;
}

HumanB::~HumanB(){
}

void	HumanB::attack()const
{
	if (weapon)
		std::cout << name << " attacks with " << weapon->getType() << std::endl;
	else
		std::cout << name << " does not have a weapon" <<  std::endl;
}

void	HumanB::setWeapon(const Weapon& given_weapon)
{
	weapon = &given_weapon;
}
