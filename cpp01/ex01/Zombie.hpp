/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:07:46 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 14:38:50 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP
# include <iostream>    //for std::cout, std::cin, std::cerr
# include <string>      //for std::string
# include <array>		//for std::array

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();	//default
		Zombie(std::string zombieName);
		~Zombie();
		
		void	announce();
};

#endif
