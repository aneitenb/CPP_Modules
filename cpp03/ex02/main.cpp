/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/12 15:45:23 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap ClapTrap("ClapTrap");
	ScavTrap ScavTrap("ScavTrap");
	FragTrap FragTrap("FragTrap");

	std::cout << "\n" << std::endl;
	std::cout << "ClapTrap HP: " << ClapTrap.getHitPoints() << "  | EP: " << ClapTrap.getEnergyPoints() << "  | Damage points: " << ClapTrap.getDamagePoints() << std::endl;
	std::cout << "ScavTrap HP: " << ScavTrap.getHitPoints() << " | EP: " << ScavTrap.getEnergyPoints() << " | Damage points: " << ScavTrap.getDamagePoints() << std::endl;
	std::cout << "FragTrap HP: " << FragTrap.getHitPoints() << " | EP: " << FragTrap.getEnergyPoints() << " | Damage points: " << FragTrap.getDamagePoints() << std::endl;
	std::cout << "\n" << std::endl;
	
	ClapTrap.setDamagePoints(2);
	std::cout << "ClapTrap DP: " << ClapTrap.getDamagePoints() << std::endl;
	ClapTrap.attack("ScavTrap");
	ScavTrap.takeDamage(2);
	FragTrap.attack("ScavTrap");
	ScavTrap.takeDamage(30);
	ScavTrap.beRepaired(15);
	FragTrap.attack("ClapTrap");
	ClapTrap.takeDamage(30);
	ClapTrap.beRepaired(20);
	ClapTrap.attack("ScavTrap");
	ScavTrap.attack("FragTrap");
	FragTrap.takeDamage(20);
	ScavTrap.attack("FragTrap");
	FragTrap.takeDamage(20);
	ScavTrap.attack("FragTrap");
	FragTrap.takeDamage(20);
	// FragTrap.setHitPoints(0);
	FragTrap.attack("ScavTrap");
	FragTrap.highFivesGuys();

	std::cout << std::endl;
	
	std::cout << "\nScavTrap HP: " << ScavTrap.getHitPoints() << " | EP: " << ScavTrap.getEnergyPoints() << " | Damage points: " << ScavTrap.getDamagePoints() << std::endl;
	std::cout << "FragTrap HP: " << FragTrap.getHitPoints() << " | EP: " << FragTrap.getEnergyPoints() << " | Damage points: " << FragTrap.getDamagePoints() << std::endl;
	std::cout << "ClapTrap HP: " << ClapTrap.getHitPoints() << "  | EP: " << ClapTrap.getEnergyPoints() << "  | Damage points: " << ClapTrap.getDamagePoints() << std::endl << std::endl;
}
