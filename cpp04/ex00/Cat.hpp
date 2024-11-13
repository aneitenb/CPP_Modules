/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:42:49 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 19:11:11 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat& copy);
		~Cat();
		Cat& operator=(const Cat&);

		void	makeSound() const override;
};
