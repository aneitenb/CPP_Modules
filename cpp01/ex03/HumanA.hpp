/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:24:45 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 14:38:29 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

# define HUMANA_HPP
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		const Weapon& weapon;
	public:
		~HumanA();
		
		HumanA(const std::string& given_name, const Weapon& given_weapon);

		void	attack()const;
};

#endif
