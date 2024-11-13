/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:31:52 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/13 19:06:22 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal& copy)
{ 
	this->type = copy.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy asignment called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string		Animal::getType(void) const{
	return this->type;
}

void	Animal::makeSound(void)const{
	std::cout << "Ooommmmmmmmmmmmmm" << std::endl;
}
