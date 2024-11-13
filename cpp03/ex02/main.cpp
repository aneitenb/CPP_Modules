/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 10:34:07 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap claptrap("claptrap");
	ScavTrap scavtrap("scavtrap");
	FragTrap fragtrap("fragtrap");

	std::cout << "\n" << std::endl;
	std::cout << "claptrap HP: " << claptrap.getHitPoints() << "  | EP: " << claptrap.getEnergyPoints() << "  | Damage points: " << claptrap.getDamagePoints() << std::endl;
	std::cout << "scavtrap HP: " << scavtrap.getHitPoints() << " | EP: " << scavtrap.getEnergyPoints() << " | Damage points: " << scavtrap.getDamagePoints() << std::endl;
	std::cout << "fragtrap HP: " << fragtrap.getHitPoints() << " | EP: " << fragtrap.getEnergyPoints() << " | Damage points: " << fragtrap.getDamagePoints() << std::endl;
	std::cout << "\n" << std::endl;
	
	claptrap.setDamagePoints(2);
	std::cout << "claptrap DP: " << claptrap.getDamagePoints() << std::endl;
	claptrap.attack("scavtrap");
	scavtrap.takeDamage(2);
	fragtrap.attack("scavtrap");
	scavtrap.takeDamage(30);
	scavtrap.beRepaired(15);
	fragtrap.attack("claptrap");
	claptrap.takeDamage(30);
	claptrap.beRepaired(20);
	claptrap.attack("scavtrap");
	scavtrap.attack("fragtrap");
	fragtrap.takeDamage(20);
	scavtrap.attack("fragtrap");
	fragtrap.takeDamage(20);
	scavtrap.attack("fragtrap");
	fragtrap.takeDamage(20);
	// fragtrap.setHitPoints(0);
	fragtrap.attack("scavtrap");
	fragtrap.highFivesGuys();

	std::cout << std::endl;
	
	std::cout << "\nscavtrap HP: " << scavtrap.getHitPoints() << " | EP: " << scavtrap.getEnergyPoints() << " | Damage points: " << scavtrap.getDamagePoints() << std::endl;
	std::cout << "fragtrap HP: " << fragtrap.getHitPoints() << " | EP: " << fragtrap.getEnergyPoints() << " | Damage points: " << fragtrap.getDamagePoints() << std::endl;
	std::cout << "claptrap HP: " << claptrap.getHitPoints() << "  | EP: " << claptrap.getEnergyPoints() << "  | Damage points: " << claptrap.getDamagePoints() << std::endl << std::endl;
}
