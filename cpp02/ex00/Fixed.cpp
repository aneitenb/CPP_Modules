/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:40 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/07 13:25:49 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

//Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
}

/*
Copy constructor
*this is a pointer to the current object, i.e., the instance of the class 
that is calling the function. The expression *this is the dereferenced version 
of this, which gives you a reference to the current object itself rather than a 
pointer.
*/
Fixed::Fixed(const Fixed &other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Copies the data from "other" to the current object (*this)
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits()const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const rawBits)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = rawBits;
}
