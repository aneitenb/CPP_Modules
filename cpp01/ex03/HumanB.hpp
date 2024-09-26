/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:24:56 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 15:18:50 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB
{
	private:
	   std::string  	name;
	   const Weapon*	weapon;
	public:
	   HumanB(const std::string& given_name);
	  ~HumanB();

	   void	attack()const;
	   void	setWeapon(const Weapon& given_weapon);
};


#endif