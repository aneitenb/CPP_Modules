/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:12:15 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/07 14:22:53 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP

# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
private:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			damagePoints;
public:
	ClapTrap();
	ClapTrap(std::string newName);
	~ClapTrap();
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif