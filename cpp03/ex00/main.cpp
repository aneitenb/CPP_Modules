/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:05:26 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/12 16:02:20 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap ClapTrap("Trump");
	
	ClapTrap.attack("Harris");
	ClapTrap.takeDamage(9);
	ClapTrap.attack("Putin");
	ClapTrap.beRepaired(20);
	ClapTrap.attack("Putin");
}
