/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 15:00:34 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>


int	main()
{
	ClapTrap clap;
	ScavTrap scav;
	FragTrap frag;

	std::cout << "\n" << std::endl;
	std::cout << "clap HP: " << clap.getHitPoints() << "  | EP: " << clap.getEnergyPoints() << "  | Damage points: " << clap.getDamagePoints() << std::endl;
	std::cout << "scav HP: " << scav.getHitPoints() << " | EP: " << scav.getEnergyPoints() << " | Damage points: " << scav.getDamagePoints() << std::endl;
	std::cout << "frag HP: " << frag.getHitPoints() << " | EP: " << frag.getEnergyPoints() << " | Damage points: " << frag.getDamagePoints() << std::endl;
	std::cout << "\n" << std::endl;
	
	clap.setDamagePoints(2);
	std::cout << "clap DP: " << clap.getDamagePoints() << std::endl;
	clap.attack("scav");
	scav.takeDamage(2);
	frag.attack("scav");
	scav.takeDamage(30);
	scav.beRepaired(15);
	frag.attack("clap");
	clap.takeDamage(30);
	clap.beRepaired(20);
	clap.attack("scav");
	scav.attack("frag");
	frag.takeDamage(20);
	scav.attack("frag");
	frag.takeDamage(20);
	scav.attack("frag");
	frag.takeDamage(20);
	// frag.setHitPoints(0);
	frag.attack("scav");
	frag.highFivesGuys();

	std::cout << std::endl;
	
	std::cout << "\nscav HP: " << scav.getHitPoints() << " | EP: " << scav.getEnergyPoints() << " | Damage points: " << scav.getDamagePoints() << std::endl;
	std::cout << "frag HP: " << frag.getHitPoints() << " | EP: " << frag.getEnergyPoints() << " | Damage points: " << frag.getDamagePoints() << std::endl;
	std::cout << "clap HP: " << clap.getHitPoints() << "  | EP: " << clap.getEnergyPoints() << "  | Damage points: " << clap.getDamagePoints() << std::endl << std::endl;
}
