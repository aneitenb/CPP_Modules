/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:44 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/11 15:05:33 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed b(10);
	Fixed c(2.42f);
	Fixed d(b);
	a = c;

	std::cout << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;

	std::cout << std::endl;
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << std::endl;

	std::cout << std::boolalpha;	//changes to true or false statemetns
	std::cout << (a < b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (d > b) << std::endl;
	std::cout << (b >= b) << std::endl;
	std::cout << (a == a) << std::endl;
	std::cout << (a != a) << std::endl;

	std::cout << std::endl;

	std::cout << (a + a) << std::endl;
	std::cout << (b - a) << std::endl;
	std::cout << (c * b) << std::endl;
	std::cout << (d / d) << std::endl;

	std::cout << std::endl;

	std::cout << b << std::endl;
	std::cout << ++b << std::endl;
	std::cout << b << std::endl;
	std::cout << b++ << std::endl;
	std::cout << b << std::endl;

	std::cout << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << b.min( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << a.max( a, b ) << std::endl;

	std::cout << std::endl;
	
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max(a, b) << std::endl;
	
	return 0;
}
