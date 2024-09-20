/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:11:03 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/20 15:50:56 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//	this function creates a zombie, names it, and the zombie announces itself.
void randomChump(std::string name) 
{
    Zombie rando(name);  // c++ automatically allocates on the stack when not using "new" keyword
	
    rando.announce();
}