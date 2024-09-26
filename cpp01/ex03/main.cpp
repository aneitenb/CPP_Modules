/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:43:05 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 15:31:22 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
	Weapon club = Weapon("huge spoon the size of a giraffe");
	HumanA bob("Bob", club);

	bob.attack();
	club.setType("glob of jelly that engulfs opponent");
	bob.attack();
	}
	{
	Weapon club = Weapon("huge spoon the size of a giraffe");
	HumanB jim("Jim");

	jim.attack();
	jim.setWeapon(club);
	club.setType("mini monkeys that tickle opponent incapable");
	jim.attack();
	}
	return (0);
}
