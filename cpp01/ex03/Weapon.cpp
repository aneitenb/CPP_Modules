/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:59:50 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 15:11:24 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("undefined weapon") {}

Weapon::Weapon(const std::string& given_type)
{
	type = given_type;
}

const std::string& Weapon::getType()const
{
	return (type);
}

void Weapon::setType(const std::string& newtype)
{
	type = newtype;
}

Weapon::~Weapon(){
}
