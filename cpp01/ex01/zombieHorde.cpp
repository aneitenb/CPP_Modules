/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:07:39 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 15:03:07 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	if (N < 0)
		return (NULL);
	horde = new Zombie[N];	//this uses the default constructor
	for(int i = 0; i < N; i++)
	{
		horde[i] = Zombie(name);	
	}
	return(horde);
}
