/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:23:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/20 16:16:46 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie	*Barbie;
	
	Barbie = newZombie("Barbie");
	Barbie->announce();
	delete Barbie;	//"delete" function is used to clear allocated heap memory from newZombie
	
	randomChump("Ken");	//this function only uses stack memory so we don't need to delete
	
	return (0);
}