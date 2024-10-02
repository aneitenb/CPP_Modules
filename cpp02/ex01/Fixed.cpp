/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:40 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/02 19:37:09 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixed_point = 0;
}

// Copy constructor: used to create a new object by copying an existing object
Fixed::Fixed(const Fixed &other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // Copies the data from "other" to the current object (*this)
}

// Int constructor: converts int to fixed point
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixed_point = value << fractional_bits;	//bit shift left by 8 (same as x256)
}			

// Float constructor: converts floating number to fixed point
Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixed_point = roundf(value * (1 << fractional_bits)); //rounds to nearest int
}

// Copy assignment operator: used when you assign one already existing object to 
// another already existing object
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixed_point = other.getRawBits();
	return (*this);
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits()const
{
	return (this->fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

// converts internal fixed-point value into a float.
float	Fixed::toFloat(void) const
{
	return (float)fixed_point / (1 << fractional_bits);
}

// converts internal fixed-point value into an integer
int		Fixed::toInt(void) const
{
	return fixed_point >> fractional_bits;	//Bit shift right to convert
	/*The right shift operator (>>) effectively divides the number by 
	powers of 2. Shifting right by 1 bit divides the number by 2, 
	shifting by 8 bits divides by 2^8 (which is 256). */
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();  /*Convert the fixed-point number to float 
	and insert into the stream */
    return out;
}
