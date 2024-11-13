/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:21 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 15:41:52 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>


/********************************************************
*				constructors/destructor 				* 
*********************************************************/
/*
** We need to call the parent (ClapTrap) constructor because when you create a 
** derived class object (ScavTrap), C++ needs to know how to initialize the 
** parent class (ClapTrap) portion of the object first. The parent class might 
** have essential initialization that needs to happen first
*/
ScavTrap::ScavTrap() : ClapTrap() {
	this->name = "defaultScav";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName) {
	this->name = newName;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

/********************************************************
*					special functions					* 
*********************************************************/
void	ScavTrap::attack(const std::string& target){
	if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " has no energy and cannot attack:(" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead and cannot attack:(" << std::endl;
	else
	{
		energyPoints -= 1;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! " 
		"(energy points remaining: " << energyPoints << ")" << std::endl;
	}
}

void	ScavTrap::guardGate(){
	if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead and cannot enter Gate Keeper Mode" << std::endl;
	else if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " has no energy and cannot enter Gate Keeper Mode" << std::endl;
	else
		std::cout << "ScavTrap " << name << " is now in Gate Keeper Mode" << std::endl;
}
