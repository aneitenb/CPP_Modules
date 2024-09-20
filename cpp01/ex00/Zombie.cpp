/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:50:14 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/20 16:00:02 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName)
{
	name = zombieName;
}

Zombie::~Zombie()
{
    std::cout << name << " is being destroyed... **what was I maaade for?**\n";
}

void	Zombie::announce(void)
{
    std::cout << name << ":  BraiiiiiiinnnzzzZ...\n";
}
