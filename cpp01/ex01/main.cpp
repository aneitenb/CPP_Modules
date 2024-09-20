/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:06:46 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/20 16:52:33 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    Zombie  *Barbie;
    int     N;
    
    N = 42;
    Barbie = zombieHorde(N, "Barbie");
    for (int i = 0; i < N; i++)
    {
        Barbie[i].announce();
    }
    delete[] Barbie;
    return (0);
}
