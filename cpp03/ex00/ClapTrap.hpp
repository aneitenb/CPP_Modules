/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:12:15 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/14 13:02:03 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** pragma prevents the "multiple inclusion" problem. When you include a header 
** file multiple times (which can happen indirectly), this ensures the content 
** is only processed once by the compiler. This prevents duplicate definitions 
** and compilation errors.
*/
#pragma once
#include <string>

class ClapTrap
{
private:
	std::string		name;		
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;
public:
	ClapTrap();
	ClapTrap(std::string newName);
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
	~ClapTrap();
	
	void	showStats(std::string named);
	void	setHitPoints(unsigned int points);
	void	setEnergyPoints(unsigned int points);
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
