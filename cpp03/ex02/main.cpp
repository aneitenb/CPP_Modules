/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/14 13:43:14 by aneitenb         ###   ########.fr       */
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
	FragTrap fred(frag);

	clap.showStats("clap");
	scav.showStats("scav");
	frag.showStats("frag");
	fred.showStats("fred");
	
	clap.attack("scav");
	scav.takeDamage(0);
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
	frag.setHitPoints(0);
	frag.attack("scav");
	frag.highFivesGuys();

	clap.showStats("clap");
	scav.showStats("scav");
	frag.showStats("frag");
	fred.showStats("fred");

	fred = frag;
	frag.showStats("frag");
	fred.showStats("fred");
}
