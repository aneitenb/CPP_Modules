/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:52:19 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/18 11:17:35 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time

int main(void) {
	// Seed random number generator for robotomy
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	try {
		std::cout << "************************************************" << std::endl;
		std::cout << "*               Intern Tests                   *" << std::endl;
		std::cout << "************************************************" << std::endl;
		
		// Create an intern and bureaucrats for testing
		Intern someRandomIntern;
		std::cout << "Created intern and bureaucrats for testing" << std::endl;
		std::cout << std::endl;

		std::cout << "***************************************" << std::endl;
		std::cout << "*        Multiple Interns Test        *" << std::endl;
		std::cout << "***************************************" << std::endl;

		std::cout << "Test 1: Testing multiple intern instances" << std::endl;
		Intern intern1;
		Intern intern2;
		Intern intern3;
		
		AForm* form1 = intern1.makeForm("shrubbery creation", "park");
		AForm* form2 = intern2.makeForm("robotomy request", "employee123");
		AForm* form3 = intern3.makeForm("presidential pardon", "prisoner42");
		
		std::cout << "All three interns successfully created forms:" << std::endl;
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		std::cout << std::endl;
		
		std::cout << "************************************************" << std::endl;
		std::cout << "*             Copy Constructor Test           *" << std::endl;
		std::cout << "************************************************" << std::endl;

		std::cout << "Test 2: Testing intern copy constructor and assignment" << std::endl;
		Intern originalIntern;
		Intern copiedIntern(originalIntern);
		Intern assignedIntern;
		assignedIntern = originalIntern;
		
		AForm* originalForm = originalIntern.makeForm("robotomy request", "original");
		AForm* copiedForm = copiedIntern.makeForm("robotomy request", "copied");
		AForm* assignedForm = assignedIntern.makeForm("robotomy request", "assigned");
		
		std::cout << "All intern copies work correctly:" << std::endl;
		std::cout << *originalForm << std::endl;
		std::cout << *copiedForm << std::endl;
		std::cout << *assignedForm << std::endl;
		std::cout << std::endl;

		std::cout << "************************************************" << std::endl;
		std::cout << "*         Invalid Form Creation Tests         *" << std::endl;
		std::cout << "************************************************" << std::endl;
		
		std::cout << "Test 3: Attempting to create invalid forms" << std::endl;
		
		std::string invalidForms[] = {
			"tax evasion",
			"coffee making", 
			"vacation request",
			"expense report",
			"",
			"ROBOTOMY REQUEST",  // wrong case
			"shrubbery"         // incomplete name./D	
		};
		
		for (int i = 0; i < 7; i++) {
			try {
				std::cout << "Trying to create: \"" << invalidForms[i] << "\"" << std::endl;
				AForm* invalidForm = someRandomIntern.makeForm(invalidForms[i], "target");
				std::cout << "Unexpected success! Form: " << *invalidForm << std::endl;
				delete invalidForm;
			} catch (std::exception& e) {
				std::cout << "Expected error: " << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		
		std::cout << "************************************************" << std::endl;
		std::cout << "*                Cleanup                      *" << std::endl;
		std::cout << "************************************************" << std::endl;
		
		// Clean up allocated memory
		delete form1;
		delete form2;
		delete form3;
		delete originalForm;
		delete copiedForm;
		delete assignedForm;
		
		std::cout << "All tests completed successfully!" << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Unexpected exception in main: " << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}
