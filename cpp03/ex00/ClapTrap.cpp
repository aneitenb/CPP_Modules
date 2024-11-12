/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:11:59 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/12 16:01:16 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damagePoints = 0;
}

ClapTrap::ClapTrap(std::string newName){
	std::cout << "ClapTrap " << newName << " constructor called" << std::endl;
	this->name = newName;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damagePoints = 0;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}
	
void	ClapTrap::attack(const std::string& target){
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy and cannot attack:(" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead and cannot attack:(" << std::endl;
	else
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damagePoints << " points of damage! " <<
		"(energy remaining: " << this->energyPoints << ")" << std::endl;	
	}
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (hitPoints <= (int)amount)
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
		std::cout << "ClapTrap " << name << " has no energy and cannot be repaired" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead and cannot be repaired" << std::endl;
	else
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs " << amount << " points of damage! (health points: " << hitPoints << " | energy points: " << energyPoints << ")" << std::endl;
	}
}
