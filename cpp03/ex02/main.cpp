/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/09 16:22:38 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap Aida("Aida");
	ScavTrap Demon("Demon");
	ScavTrap Angel("Angel");

	std::cout << "\n" << std::endl;
	std::cout << "Aida HP: " << Aida.getHitPoints() << "  | EP: " << Aida.getEnergyPoints() << "  | Damage points: " << Aida.getDamagePoints() << std::endl;
	std::cout << "Demon HP: " << Demon.getHitPoints() << " | EP: " << Demon.getEnergyPoints() << " | Damage points: " << Demon.getDamagePoints() << std::endl;
	std::cout << "Angel HP: " << Angel.getHitPoints() << " | EP: " << Angel.getEnergyPoints() << " | Damage points: " << Angel.getDamagePoints() << std::endl;
	std::cout << "\n" << std::endl;
	
	Aida.setDamagePoints(2);
	std::cout << "Aida DP: " << Aida.getDamagePoints() << std::endl;
	Aida.attack("Demon");
	Demon.takeDamage(2);
	Angel.attack("Demon");
	Demon.takeDamage(20);
	Demon.beRepaired(15);
	Angel.attack("Aida");
	Aida.takeDamage(11);
	Aida.beRepaired(20);
	Aida.attack("Demon");
	Demon.takeDamage(2);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	// Angel.setHitPoints(0);
	Angel.attack("Demon");
	Demon.guardGate();

	std::cout << "\n" << std::endl;
	std::cout << "\nDemon HP: " << Demon.getHitPoints() << " | EP: " << Demon.getEnergyPoints() << " | Damage points: " << Demon.getDamagePoints() << std::endl;
	std::cout << "Angel HP: " << Angel.getHitPoints() << " | EP: " << Angel.getEnergyPoints() << " | Damage points: " << Angel.getDamagePoints() << std::endl;
	std::cout << "Aida HP: " << Aida.getHitPoints() << "  | EP: " << Aida.getEnergyPoints() << "  | Damage points: " << Aida.getDamagePoints() << std::endl << std::endl;
}
