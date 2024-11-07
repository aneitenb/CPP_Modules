/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/07 17:56:55 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap Alex("Alex");
	ScavTrap Debbie("Debbie");
	ScavTrap Tom("Tom");

	std::cout << "\nDebbie HP: " << Debbie.getHitPoints() << " | EP: " << Debbie.getEnergyPoints() << " | Damage points: " << Debbie.getDamagePoints() << std::endl;
	std::cout << "Tom    HP: " << Tom.getHitPoints() << " | EP: " << Tom.getEnergyPoints() << " | Damage points: " << Tom.getDamagePoints() << std::endl;
	std::cout << "Alex   HP: " << Alex.getHitPoints() << "  | EP: " << Alex.getEnergyPoints() << "  | Damage points: " << Alex.getDamagePoints() << std::endl << std::endl;
	
	Alex.setEnergyPoints(2);
	Alex.attack("Debbie");
	Debbie.takeDamage(0);
	Tom.attack("Debbie");
	Debbie.takeDamage(20);
	Debbie.beRepaired(15);
	Tom.attack("Alex");
	Alex.takeDamage(11);
	Alex.beRepaired(20);
	Alex.attack("Greg");
	Debbie.attack("Tom");
	Tom.takeDamage(20);
	Debbie.attack("Tom");
	Tom.takeDamage(20);
	Debbie.attack("Tom");
	Tom.takeDamage(20);
	Tom.setHitPoints(0);
	Tom.attack("Debbie");
	Debbie.guardGate();

	
std::cout << "\nDebbie HP: " << Debbie.getHitPoints() << " | EP: " << Debbie.getEnergyPoints() << " | Damage points: " << Debbie.getDamagePoints() << std::endl;
std::cout << "Tom    HP: " << Tom.getHitPoints() << " | EP: " << Tom.getEnergyPoints() << " | Damage points: " << Tom.getDamagePoints() << std::endl;
std::cout << "Alex   HP: " << Alex.getHitPoints() << "  | EP: " << Alex.getEnergyPoints() << "  | Damage points: " << Alex.getDamagePoints() << std::endl << std::endl;
}
