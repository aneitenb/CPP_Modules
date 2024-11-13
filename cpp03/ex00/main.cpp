/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 14:54:03 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap Trump("Trump");
	ClapTrap clippy;
	ClapTrap Bertha(Trump);
	
	
	clippy = Trump;
	Bertha.attack("rando");
	Trump.attack("Harris");
	Trump.takeDamage(9);
	Trump.attack("Putin");
	Trump.beRepaired(20);
	Trump.attack("Putin");
}
