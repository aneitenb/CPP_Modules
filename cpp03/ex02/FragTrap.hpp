/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:17:43 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 15:40:55 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define UINT_MAX 4294967295
# include "ClapTrap.hpp"


class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string newName);
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
	~FragTrap();
	
	void			attack(const std::string& target);
	void 			highFivesGuys(void);
};
