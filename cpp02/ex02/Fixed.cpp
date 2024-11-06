/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:40 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/06 11:00:40 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*		Constructors		*/
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	fixedPoint = value << fractionalBits;
}			

Fixed::Fixed(float value)
{
	std::cout << "Float constructor called" << std::endl;
	fixedPoint = roundf(value * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPoint = other.getRawBits();
	return (*this);
}

/*		Deconstructor		*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*********************************************
**			Comparison Operators			**
**********************************************/
bool	Fixed::operator>(const Fixed &other) const{
	return this->fixedPoint > other.fixedPoint;
}

bool	Fixed::operator<(const Fixed &other) const{
	return this->fixedPoint < other.fixedPoint;
}

bool	Fixed::operator>=(const Fixed &other) const{
	return this->fixedPoint >= other.fixedPoint;
}

bool	Fixed::operator<=(const Fixed &other) const{
	return this->fixedPoint <= other.fixedPoint;
}

bool	Fixed::operator==(const Fixed &other) const{
	return this->fixedPoint == other.fixedPoint;
}

bool	Fixed::operator!=(const Fixed &other) const{
	return this->fixedPoint != other.fixedPoint;
}


/*********************************************
**			Arithmetic Operators			**
**********************************************/
Fixed	Fixed::operator+(const Fixed &other) const{
	Fixed	result;

	result.setRawBits(this->toFloat() + other.toFloat());
	return result;
}

Fixed	Fixed::operator-(const Fixed &other) const{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const{
	return Fixed(this->toFloat() / other.toFloat());
}


/*************************************************
**		Increment/Decrement Operators			**
**************************************************/
Fixed& Fixed::operator++(){		//pre-increment
	this->fixedPoint += 1;
	return (*this);
}				

Fixed	Fixed::operator++(int){	//post-increment
	Fixed	temp;

	temp = *this;        		//copy the entire object, not just the raw value
	this->fixedPoint += 1;
	return (temp);
}

Fixed&	Fixed::operator--(){	//pre-decrement
	this->fixedPoint -= 1;
	return (*this);
}	
		
Fixed	Fixed::operator--(int){	//post-decrement
	Fixed	temp;

	temp = *this;
	this->fixedPoint -= 1;
	return (temp);
}		


/*****************************************
**		Static Member Functions			**
******************************************/
Fixed& Fixed::min(Fixed& a, Fixed& b){
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b){
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	if (a > b)
		return a;
	return b;
}


/*		Member Functions		*/
int	Fixed::getRawBits()const
{
	return (this->fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)fixedPoint / (1 << fractionalBits);
}


int		Fixed::toInt(void) const
{
	return fixedPoint >> fractionalBits;
}


// Convert the fixed-point number to float and insert into the stream 
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) 
{
	out << fixed.toFloat();  
	return out;
}
