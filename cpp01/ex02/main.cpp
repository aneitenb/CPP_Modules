/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:27:40 by aneitenb          #+#    #+#             */
/*   Updated: 2024/09/26 11:38:07 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

//	Key Differences Between References and Pointers:
//	References:
//		Must be initialized when declared.
//		Cannot be null (must always refer to a valid variable).
//		Do not require dereferencing (no need for * or & to access or modify the value).
//		Are syntactically simpler and often safer than pointers.
//	Pointers:
//		Can be declared without initialization (can be null).
//		Can point to different variables or objects at different times.
//		Need to be dereferenced using * to access the value they point to.
int main()
{
	std::string		stringOG = "HI THIS IS BRAIN";
	std::string*	stringPTR = &stringOG;
	std::string&	stringREF = stringOG;
	
	std::cout << "The memory address of the string variable: " << &stringOG << std::endl;
	std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string variable: " << stringOG << std::endl;
	std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF: " << stringREF <<std::endl;

	return (0);
}