/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:47:04 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 14:39:04 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <iostream>    //for std::cout, std::cin, std::cerr
# include <string>      //for std::string

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(std::string zombieName);
		~Zombie();
		
		void	announce();
};

#endif
