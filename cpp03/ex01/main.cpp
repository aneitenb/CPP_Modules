/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/14 13:33:08 by aneitenb         ###   ########.fr       */
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

	clap.showStats("clap");
	Demon.showStats("Demon");
	Angel.showStats("Angel");
	
	Angel.attack("Demon");
	Demon.takeDamage(20);
	Angel.attack("clap");
	clap.takeDamage(20);
	clap.beRepaired(20);
	clap.attack("Demon");
	
	clap.showStats("clap");
	Demon.showStats("Demon");
	Angel.showStats("Angel");
	
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Demon.attack("Angel");
	Angel.takeDamage(20);
	Angel.setHitPoints(0);
	Angel.guardGate();
	Demon.guardGate();

	clap.showStats("clap");
	Demon.showStats("Demon");
	Angel.showStats("Angel");
}
