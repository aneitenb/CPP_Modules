/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:52:08 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 19:17:24 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		
		WrongCat(WrongCat& copy);
		~WrongCat();
		WrongCat& operator=(const WrongCat&);

		void	makeSound() const;
};
