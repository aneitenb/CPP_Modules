/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:42:57 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 19:11:08 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <string>
#include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog& copy);
		~Dog();
		Dog& operator=(const Dog&);

		void	makeSound() const override;
};
