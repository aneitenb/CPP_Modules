/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:06:10 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 14:06:43 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//	this function creates a zombie, names it, and returns it so you can use 
//	it outside of the function scope.
Zombie*	newZombie(std::string name)
{
	return new Zombie(name);	//the "new" function allocates memory on the heap
}