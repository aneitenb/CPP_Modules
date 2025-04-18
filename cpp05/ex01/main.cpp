/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:52:19 by aneitenb          #+#    #+#             */
/*   Updated: 2025/04/18 17:44:52 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try {
		std::cout << "****************************************" << std::endl;
		std::cout << "*            Setup Bureaucrats          *" << std::endl;
		std::cout << "****************************************" << std::endl;
		Bureaucrat x;
		Bureaucrat a("John Hancock", 1);
		Bureaucrat b("Nicolas Cage", 150);
		
		std::cout << x << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*        Basic Form Tests         *" << std::endl;
		std::cout << "****************************************" << std::endl;
		Form y;
		Form c("Declaration of Independence", 1, 1);
		Form d("Social Security Information", 150, 150);
		
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*    Throw Exceptions Form Tests       *" << std::endl;
		std::cout << "****************************************" << std::endl;
		try {
			Form f("F", 0, 1);
			std::cout << c << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception creating Form F: " << e.what() << std::endl;
		}
		
		try {
			Form g("G", 151, 1);
			std::cout << d << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception creating Form G: " << e.what() << std::endl;
		}

		try {
			Form h("H", 1, 0);
			std::cout << c << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception creating Form H: " << e.what() << std::endl;
		}
		
		try {
			Form i("I", 1, 160);
			std::cout << c << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Exception creating Form I: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "******************************************" << std::endl;
		std::cout << "* Form copy constructor/assignment Tests *" << std::endl;
		std::cout << "******************************************" << std::endl;

		Form j = c;
		std::cout << "j should equal c:" << std::endl;
		std::cout << "Form j name is: " << j << std::endl;
		
		Form k(d);
		std::cout << "k should equal d:" << std::endl;
		std::cout << "Form k name is: " << k << std::endl;
		std::cout << std::endl;
		
		std::cout << "******************************************" << std::endl;
		std::cout << "*           Permissions Tests            *" << std::endl;
		std::cout << "******************************************" << std::endl;
		a.signForm(c);
		std::cout << c << std::endl;
		a.signForm(d);
		std::cout << d << std::endl;
		b.signForm(c);
		std::cout << c << std::endl;
		b.signForm(d);
		std::cout << d << std::endl;
		std::cout << std::endl;
		b.signForm(y);
		std::cout << y << std::endl;
		std::cout << std::endl;

		Form l("mental health check", 100, 100);
		b.signForm(l);
		std::cout << b << std::endl;
		std::cout << l << std::endl;
		std::cout << std::endl;

		a.signForm(l);
		std::cout << a << std::endl;
		std::cout << l << std::endl;
	} 
	catch (const std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	
	return 0;
}
