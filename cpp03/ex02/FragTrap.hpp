/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:17:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/12 15:10:00 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define UINT_MAX 4294967295
# include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	
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
	void 			highFivesGuys(void);
};
