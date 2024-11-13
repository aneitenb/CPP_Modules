/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 15:48:30 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap clap;
	ScavTrap Demon("Demon");
	ScavTrap Angel("Angel");

	std::cout << "\n" << std::endl;
	std::cout << "clap HP: " << clap.getHitPoints() << "  | EP: " << clap.getEnergyPoints() << "  | Damage points: " << clap.getDamagePoints() << std::endl;
	std::cout << "Demon HP: " << Demon.getHitPoints() << " | EP: " << Demon.getEnergyPoints() << " | Damage points: " << Demon.getDamagePoints() << std::endl;
	std::cout << "Angel HP: " << Angel.getHitPoints() << " | EP: " << Angel.getEnergyPoints() << " | Damage points: " << Angel.getDamagePoints() << std::endl;
	std::cout << "\n" << std::endl;
	
	clap.setDamagePoints(2);
	std::cout << "clap DP: " << clap.getDamagePoints() << std::endl;
	clap.attack("Demon");
	Demon.takeDamage(2);
	Angel.attack("Demon");
	Demon.takeDamage(20);
	Demon.beRepaired(15);
	Angel.attack("Aida");
	clap.takeDamage(11);
	clap.beRepaired(20);
	clap.attack("Demon");
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
	std::cout << "Aida HP: " << clap.getHitPoints() << "  | EP: " << clap.getEnergyPoints() << "  | Damage points: " << clap.getDamagePoints() << std::endl << std::endl;
}
