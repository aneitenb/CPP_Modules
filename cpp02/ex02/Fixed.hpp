/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:36 by aneitenb          #+#    #+#             */
/*   Updated: 2024/11/07 14:00:16 by aneitenb         ###   ########.fr       */
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
	/*		Constructors		*/
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);

	/*		Deconstructor		*/
	~Fixed();

	/*		Copy assignment operator		*/
	Fixed& operator=(const Fixed& other);

	/*		Comparison Operators		*/
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	/*		Arithmetic Operators		*/
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	/*		Increment/Decrement Operators		*/
	Fixed	&operator++();					//pre-increment
	Fixed	operator++(int);				//post-increment
	Fixed	&operator--();					//pre-decrement
	Fixed	operator--(int);				//post-decrement

	/*		Static Member Functions			*/
	static	Fixed& min(Fixed& a, Fixed& b);
	static	const Fixed& min(const Fixed& a, const Fixed& b);
	static	Fixed& max(Fixed& a, Fixed& b);
	static	const Fixed& max(const Fixed& a, const Fixed& b);
	
	/*		Member Functions		*/
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
};

/*		Stream operator overload		*/
std::ostream &operator<<(std::ostream& out, const Fixed& fixed);

#endif