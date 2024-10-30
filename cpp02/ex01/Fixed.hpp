/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:36 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/30 12:17:10 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					fixedPoint;
	static const int	fractionalBits = 8;
public:
	Fixed();								// Default constructor
	Fixed(const int value);					// Int constructor
	Fixed(const float value);				// Float constructor
	Fixed(const Fixed &other);				// Copy constructor
	~Fixed();

	Fixed &operator=(const Fixed &other); 	// Copy assignment operator
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

/* 
** We declare the << operator overload as a non-member function, meaning it can
** only access public members of the Fixed class.
** This function returns a refernce to an std::ostream object, which allows you 
** to chain multiple << operations together.
** The first parameter represents the output stream where the formatted output 
** will be sent.
** The second parameter references a Fixed object(the one you want to output).
** The purpose of this function declaration is to define a way to output a Fixed 
** object to an output stream (like std::cout). When you use the << operator 
** with a Fixed instance, this function will be invoked to format the output.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif