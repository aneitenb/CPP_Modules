/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:11:59 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/14 13:17:24 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

/********************************************************
*		constructors/copy assignment/destructor 		* 
*********************************************************/
ClapTrap::ClapTrap(){
	std::cout << "Claptrap default constructor called" << std::endl;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string newName){
	std::cout << "Claptrap " << newName << " constructor called" << std::endl;
	this->name = newName;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assignment called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

/********************************************************
*					get/set functions					* 
*********************************************************/
void	ClapTrap::showStats(std::string named){
	std::cout << "--------STATS--------" << std::endl;
	std::cout << named << " name: " << this->name << std::endl;
	std::cout << named << " health points: " << this->hitPoints << std::endl;
	std::cout << named << " energy points: " << this->energyPoints << std::endl;
	std::cout << named << " damage points: " << this->attackDamage << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::setHitPoints(unsigned int points){
	this->hitPoints = points;
}

void	ClapTrap::setEnergyPoints(unsigned int points){
	this->energyPoints = points;
}

/********************************************************
*					special functions					* 
*********************************************************/
void	ClapTrap::attack(const std::string& target){
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy and cannot attack:(" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead and cannot attack:(" << std::endl;
	else
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage! " <<
		"(energy remaining: " << this->energyPoints << ")" << std::endl;	
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (hitPoints <= amount)
	{
		std::cout << "ClapTrap " << name << " is dead!"<< std::endl;
		hitPoints = 0;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage! " <<
		"(health remaining: " << this->hitPoints << ")" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints == 0)
		std::cout << name << " has no energy and cannot be repaired" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead and cannot be repaired" << std::endl;
	else if (hitPoints > 4294967295 - amount)
	{
		energyPoints -= 1;
		hitPoints = 4294967295;
		std::cout << "ClapTrap " << name << " repairs to max unsigned int value! "
		<< "(health points: " << hitPoints << " | energy points: " << energyPoints << ")" << std::endl;
	}
	else
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs " << amount << " points of damage! "
		<< "(health points: " << hitPoints << " | energy points: " << energyPoints << ")" << std::endl;
	}
}
