/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:24 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/09 16:02:10 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pragma prevents the "multiple inclusion" problem. When you include a header 
** file multiple times (which can happen indirectly), this ensures the content 
** is only processed once by the compiler. This prevents duplicate definitions 
** and compilation errors.
*/
#pragma once

# define UINT_MAX 4294967295
# include "ClapTrap.hpp"

/*
** ScavTrap is a "child" or "derived" class of ClapTrap. ScavTrap inherits from
** ClapTrap using public inheritance.
** ScavTrap inherits all the base functionality from ClapTrap.
** It can override base class methods (like attack()), it can add new methods 
** (like guardGate()), it has its own constructors and destructor.
** It maintains its own copies of the member variables (name, hit points, 
** energy points, attack points)
*/
class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	
	std::string&	getName();
	unsigned int	getHitPoints();
	unsigned int	getEnergyPoints();
	unsigned int	getDamagePoints();
	void			setName(std::string new_name);
	void			setHitPoints(unsigned int points);
	void			setEnergyPoints(unsigned int points);
	void			setDamagePoints(unsigned int points);
	void			attack(const std::string& target);
	void			beRepaired(unsigned int amount);
	void			takeDamage(unsigned int amount);
	void 			guardGate();
};