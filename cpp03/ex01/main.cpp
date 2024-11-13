/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 10:32:33 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap clapTrap("Aida");
	ScavTrap Demon("Demon");
	ScavTrap Angel("Angel");

	std::cout << "\n" << std::endl;
	std::cout << "clapTrap HP: " << clapTrap.getHitPoints() << "  | EP: " << clapTrap.getEnergyPoints() << "  | Damage points: " << clapTrap.getDamagePoints() << std::endl;
	std::cout << "Demon HP: " << Demon.getHitPoints() << " | EP: " << Demon.getEnergyPoints() << " | Damage points: " << Demon.getDamagePoints() << std::endl;
	std::cout << "Angel HP: " << Angel.getHitPoints() << " | EP: " << Angel.getEnergyPoints() << " | Damage points: " << Angel.getDamagePoints() << std::endl;
	std::cout << "\n" << std::endl;
	
	clapTrap.setDamagePoints(2);
	std::cout << "clapTrap DP: " << clapTrap.getDamagePoints() << std::endl;
	clapTrap.attack("Demon");
	Demon.takeDamage(2);
	Angel.attack("Demon");
	Demon.takeDamage(20);
	Demon.beRepaired(15);
	Angel.attack("Aida");
	clapTrap.takeDamage(11);
	clapTrap.beRepaired(20);
	clapTrap.attack("Demon");
	Demon.takeDamage(2);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Angel.setHitPoints(0);
	Angel.attack("Demon");
	Demon.guardGate();

	std::cout << "\n" << std::endl;
	std::cout << "\nDemon HP: " << Demon.getHitPoints() << " | EP: " << Demon.getEnergyPoints() << " | Damage points: " << Demon.getDamagePoints() << std::endl;
	std::cout << "Angel HP: " << Angel.getHitPoints() << " | EP: " << Angel.getEnergyPoints() << " | Damage points: " << Angel.getDamagePoints() << std::endl;
	std::cout << "Aida HP: " << clapTrap.getHitPoints() << "  | EP: " << clapTrap.getEnergyPoints() << "  | Damage points: " << clapTrap.getDamagePoints() << std::endl << std::endl;
}
