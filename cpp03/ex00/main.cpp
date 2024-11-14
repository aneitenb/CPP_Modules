/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/14 13:34:03 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main()
{
	ClapTrap Calvin("Calvin");
	ClapTrap clippy;
	ClapTrap Bertha(Calvin);
	
	Calvin.showStats("Calvin");
	clippy.showStats("clippy");
	Bertha.showStats("Bertha");
	
	Calvin.attack("rando");
	Calvin.attack("rando");
	Calvin.attack("rando");
	Calvin.takeDamage(9);
	
	Calvin.showStats("Calvin");
	Bertha.showStats("Bertha");
	
	Calvin.beRepaired(21);
	Calvin.beRepaired(4294967293);
	Calvin.attack("stranger");

	Calvin.showStats("Calvin");
}
