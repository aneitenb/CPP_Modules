/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:44 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/30 12:05:17 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) 
{
	Fixed		a;
	Fixed const b(10);             // Int constructor
	Fixed const c(42.42f);         // Float constructor
	Fixed const d(b);              // Copy constructor
	
	a = Fixed(1234.4321f);         // Float constructor and assignment operator

	std::cout << "a is " << a << std::endl; // Print a as a float
	std::cout << "b is " << b << std::endl; // Print b as a float
	std::cout << "c is " << c << std::endl; // Print c as a float
	std::cout << "d is " << d << std::endl; // Print d as a float

	std::cout << "a is " << a.toInt() << " as integer" << std::endl; // Convert to int
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; // Convert to int
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; // Convert to int
	std::cout << "d is " << d.toInt() << " as integer" << std::endl; // Convert to int

	return (0);
}
