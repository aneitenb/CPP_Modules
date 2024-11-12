/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:21 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/12 15:28:22 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

/*
** We need to call the parent (ClapTrap) constructor because when you create a 
** derived class object (ScavTrap), C++ needs to know how to initialize the 
** parent class (ClapTrap) portion of the object first. The parent class might 
** have essential initialization that needs to happen first
*/
ScavTrap::ScavTrap() : ClapTrap() {
	setName("defaultScav");
	setHitPoints(100);
	setEnergyPoints(50);
	setDamagePoints(20);
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
	setName(name);
	setHitPoints(100);
	setEnergyPoints(50);
	setDamagePoints(20);
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called" << std::endl;
}

std::string&	ScavTrap::getName(){ return this->name; }

unsigned int	ScavTrap::getHitPoints(){ return this->hitPoints; }

unsigned int	ScavTrap::getEnergyPoints(){ return this->energyPoints; }

unsigned int	ScavTrap::getDamagePoints(){ return this->damagePoints; }

void	ScavTrap::setName(std::string new_name){
	this->name = new_name;
}

void	ScavTrap::setHitPoints(unsigned int points){
	if (points < UINT_MAX)
		this->hitPoints = points;
	else
		this->hitPoints = 0;
}

void	ScavTrap::setEnergyPoints(unsigned int points){
	if (points < UINT_MAX)
		this->energyPoints = points;
	else
		this->energyPoints = 0;
}

void	ScavTrap::setDamagePoints(unsigned int points){
	if (points < UINT_MAX)
		this->damagePoints = points;
	else
		this->damagePoints = 0;
}

void	ScavTrap::attack(const std::string& target){
	if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " has no energy and cannot attack:(" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead and cannot attack:(" << std::endl;
	else
	{
		energyPoints -= 1;
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << damagePoints << " points of damage! " 
		"(energy points remaining: " << energyPoints << ")" << std::endl;	
	}
}

void	ScavTrap::takeDamage(unsigned int amount){
	if (hitPoints <= (int)amount)
	{
		std::cout << "ScavTrap " << name << " is dead!"<< std::endl;
		hitPoints = 0;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ScavTrap " << name << " takes " << amount << " points of damage! " 
		<< "(health points remaining: " << hitPoints << ")" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount){
	if (energyPoints == 0)
		std::cout << "ScavTrap " << name << " has no energy and cannot be repaired";
	else if (hitPoints == 0)
		std::cout << "ScavTrap " << name << " is dead and cannot be repaired" << std::endl;
	else
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "ScavTrap " << name << " repairs " << amount << " points of damage! "
		<< "(health points remaining: " << hitPoints << " | energy points remaining: " << energyPoints << ")" << std::endl;
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
