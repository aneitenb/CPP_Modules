/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:17:47 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/09 16:29:57 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

/*
** We need to call the parent (ClapTrap) constructor because when you create a 
** derived class object (FragTrap), C++ needs to know how to initialize the 
** parent class (ClapTrap) portion of the object first. The parent class might 
** have essential initialization that needs to happen first
*/
FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setDamagePoints(30);
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

std::string&	FragTrap::getName(){ return this->name; }

unsigned int	FragTrap::getHitPoints(){ return this->hitPoints; }

unsigned int	FragTrap::getEnergyPoints(){ return this->energyPoints; }

unsigned int	FragTrap::getDamagePoints(){ return this->damagePoints; }

void	FragTrap::setName(std::string new_name){
	this->name = new_name;
}

void	FragTrap::setHitPoints(unsigned int points){
	if (points < UINT_MAX)
		this->hitPoints = points;
	else
		this->hitPoints = 0;
}

void	FragTrap::setEnergyPoints(unsigned int points){
	if (points < UINT_MAX)
		this->energyPoints = points;
	else
		this->energyPoints = 0;
}

void	FragTrap::setDamagePoints(unsigned int points){
	if (points < UINT_MAX)
		this->damagePoints = points;
	else
		this->damagePoints = 0;
}

void	FragTrap::attack(const std::string& target){
	if (energyPoints == 0)
		std::cout << "FragTrap " << name << " has no energy and cannot attack:(" << std::endl;
	else if (hitPoints == 0)
		std::cout << "FragTrap " << name << " is dead and cannot attack:(" << std::endl;
	else
	{
		energyPoints -= 1;
		std::cout << "FragTrap " << name << " attacks " << target << ", causing " << damagePoints << " points of damage!" 
		"(energy points remaining: " << energyPoints << ")" << std::endl;	
	}
}

void	FragTrap::takeDamage(unsigned int amount){
	if (hitPoints <= (int)amount)
	{
		std::cout << "FragTrap " << name << " is dead!"<< std::endl;
		hitPoints = 0;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "FragTrap " << name << " takes " << amount << " points of damage!" 
		<< "(health points remaining: " << hitPoints << ")" << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount){
	if (energyPoints == 0)
		std::cout << "FragTrap " << name << " has no energy and cannot be repaired";
	else
	{
		energyPoints -= 1;
		hitPoints += amount;
		std::cout << "FragTrap " << name << " repairs " << amount << " points of damage! "
		<< "(health points remaining: " << hitPoints << " | energy points remaining: " << energyPoints << ")" << std::endl;
	}
}

void 	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << name << " can I get a high five bro?? Cowabunga!" << std::endl;
}