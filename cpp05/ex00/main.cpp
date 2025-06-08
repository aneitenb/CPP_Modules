/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:52:19 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:15:57 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	try {
		std::cout << "****************************************" << std::endl;
		std::cout << "*            Basic Tests               *" << std::endl;
		std::cout << "****************************************" << std::endl;
		Bureaucrat x;
		Bureaucrat a("A", 1);
		Bureaucrat b("B", 150);
		
		std::cout << x << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*        Throw Exception Tests         *" << std::endl;
		std::cout << "****************************************" << std::endl;
		try {
			Bureaucrat c("C", 0);
			std::cout << c << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception creating bureaucrat C: " << e.what() << std::endl;
		}
		
		try {
			Bureaucrat d("D", 151);
			std::cout << d << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception creating bureaucrat D: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "******************************************" << std::endl;
		std::cout << "* Copy constructor/copy assignment Tests *" << std::endl;
		std::cout << "******************************************" << std::endl;
		Bureaucrat ee = a;
		std::cout << "ee should equal a:" << std::endl;
		std::cout << "Bureaucrat ee name is: " << ee << std::endl;

		Bureaucrat f(b);
		std::cout << "f should equal b:" << std::endl;
		std::cout << "Bureaucrat f name is: " << f << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "******************************************" << std::endl;
		std::cout << "*            Increment Tests             *" << std::endl;
		std::cout << "******************************************" << std::endl;
		a.decrementGrade();
		std::cout << "A bureaucrat decremented: " << a << std::endl;
		a.decrementGrade();
		std::cout << "A bureaucrat decremented: " << a << std::endl;
		a.incrementGrade();
		std::cout << "A bureaucrat incremented: " << a << std::endl;
		a.incrementGrade();
		std::cout << "A bureaucrat incremented: " << a << std::endl;
		try{
			a.incrementGrade();
			std::cout << "A bureaucrat incremented: " << a << std::endl;
		} 
		catch (const std::exception& e ) {
			std::cout << "Exception incrementing grade: " << e.what() << std::endl;	
		}
		try{
			b.decrementGrade();
			std::cout << "B bureaucrat decremented: " << a << std::endl;
		} 
		catch (const std::exception& e ) {
			std::cout << "Exception decrementing grade: " << e.what() << std::endl;	
		}
	} 
	catch (const std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	
	return 0;
}
