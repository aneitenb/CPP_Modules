/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:26:36 by aneitenb          #+#    #+#             */
/*   Updated: 2024/10/02 15:50:42 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP
/*
-The copy constructor is used to create a new object by copying an existing 
object.
-The copy assignment operator is used when you assign one already existing 
object to another already existing object.
*/
class Fixed
{
private:
	int					fixed_point;
	static const int	fractional_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &other); // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
	~Fixed();

	int		getRawBits()const;
	void	setRawBits(int const raw);
};

#endif