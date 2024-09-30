/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:39:32 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/30 14:39:32 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harlFilter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	harlFilter	customer;

	if (ac != 2)
	{
		std::cerr << "Error: Input <level> of complaint" << std::endl;
		return (1);	
	}
	customer.complain(av[1]);
	return (0);
}
