/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:16:24 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 18:32:02 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ScavTrap(std::string newName);
	ScavTrap(const ScavTrap&);
	ScavTrap& operator=(const ScavTrap&);
	~ScavTrap();

	void			attack(const std::string& target);
	void 			guardGate();
};
