/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:11:59 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/09 15:23:50 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(){
	std::cout << "Claptrap default constructor called" << std::endl;
	this->name = "Default";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damagePoints = 0;
}

ClapTrap::ClapTrap(std::string newName){
	std::cout << "Claptrap " << newName << " constructor called" << std::endl;
	this->name = newName;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damagePoints = 0;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}
	
unsigned int	ClapTrap::getHitPoints(){
	return this->hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(){
	return this->energyPoints;
}

unsigned int	ClapTrap::getDamagePoints(){
	return this->damagePoints;
}

void	ClapTrap::setHitPoints(unsigned int points){
	if (points < UINT_MAX)
		this->hitPoints = points;
	else
		this->hitPoints = 0;
}

void	ClapTrap::setEnergyPoints(unsigned int points){
	if (points < UINT_MAX)
		this->energyPoints = points;
	else
		this->energyPoints = 0;
}

void	ClapTrap::setDamagePoints(unsigned int points){
	if (points < UINT_MAX)
		this->damagePoints = points;
	else
		this->damagePoints = 0;
}
	
	
void	ClapTrap::attack(const std::string& target){
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy and cannot attack:(" << std::endl;
	else if (hitPoints == 0)
		std::cout << "ClapTrap " << name << " is dead and cannot attack:(" << std::endl;
	else
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << damagePoints << " points of damage!" << std::endl;	
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
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (energyPoints == 0)
		std::cout << "ClapTrap " << name << " has no energy and cannot be repaired";
	else
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repairs " << amount << " points of damage! (health points: " << hitPoints << " | energy points: " << energyPoints << ")" << std::endl;
	}
}
