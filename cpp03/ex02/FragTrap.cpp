/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:17:47 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 16:21:11 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/********************************************************
*				constructors/destructor 				* 
*********************************************************/
FragTrap::FragTrap() : ClapTrap() {
	this->name = "defaultFrag";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName) {
	this->name = newName;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

/********************************************************
*					special functions					* 
*********************************************************/
void 	FragTrap::highFivesGuys(void){
	if (hitPoints == 0)
		std::cout << "FragTrap " << name << " is dead and cannot high-five:(" << std::endl;
	else if (energyPoints == 0)
		std::cout << "FragTrap " << name << " has no energy and cannot high-five:(" << std::endl;
	else
		std::cout << "FragTrap " << name << ": can I get a high-five bro?? Cowabunga!" << std::endl;
}
