/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:40 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/30 13:55:29 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Default constructor
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
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
	fixedPoint = value << fractionalBits;	//bit shift left by 8 (same as x256)
}			

// Float constructor: converts floating number to fixed point
Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(value * (1 << fractionalBits)); //rounds to nearest int
}

/*
** Copy assignment operator: used when you assign one already existing object to 
** another already existing object
*/
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

int	Fixed::getRawBits()const
{
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

// converts internal fixed-point value into a float.
float	Fixed::toFloat(void) const
{
	return (float)fixedPoint / (1 << fractionalBits);
}

/*
** converts internal fixed-point value into an integer
** The right shift operator (>>) effectively divides the number by
** powers of 2. Shifting right by 1 bit divides the number by 2,
** shifting by 8 bits divides by 2^8 (which is 256).
*/
int		Fixed::toInt(void) const
{
	return fixedPoint >> fractionalBits;	//Bit shift right to convert
}


// Convert the fixed-point number to float and insert into the stream 
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
	out << fixed.toFloat();  
	return out;
}
