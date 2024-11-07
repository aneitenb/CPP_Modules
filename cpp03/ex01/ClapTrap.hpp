/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:12:15 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/07 17:26:47 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define UINT_MAX 4294967295
# include <string>

class ClapTrap
{
protected:		//Private to the outside world, but accessible to derived classes like ScavTrap
	std::string	name;		
	int			hitPoints;
	int			energyPoints;
	int			damagePoints;
public:
	ClapTrap();
	ClapTrap(std::string newName);
	~ClapTrap();
	
	unsigned int	getHitPoints();
	unsigned int	getEnergyPoints();
	unsigned int	getDamagePoints();
	void			setHitPoints(unsigned int points);
	void			setEnergyPoints(unsigned int points);
	void			setDamagePoints(unsigned int points);
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};
