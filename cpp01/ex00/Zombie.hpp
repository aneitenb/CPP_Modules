/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:47:04 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/20 15:57:28 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string zombieName);
		~Zombie();
		
		void	announce();
};

# endif