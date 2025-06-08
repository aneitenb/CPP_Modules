/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:52:19 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:17:11 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib> // For srand
#include <ctime>   // For time

int main(void) {
	//Seed the random number generator once
	//The C++ standard requires that rand() produces the same sequence if no seed is provided
	//Seeding with the current time (time(NULL)) ensures we get different random sequences
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	try {
		std::cout << "****************************************" << std::endl;
		std::cout << "*            Setup Bureaucrats          *" << std::endl;
		std::cout << "****************************************" << std::endl;
		Bureaucrat lowRank("Intern Bob", 145);
		Bureaucrat midRank("Manager Jane", 50);
		Bureaucrat highRank("Director Smith", 5);
		
		std::cout << lowRank << std::endl;
		std::cout << midRank << std::endl;
		std::cout << highRank << std::endl;
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*        Concrete Forms Creation        *" << std::endl;
		std::cout << "****************************************" << std::endl;
		ShrubberyCreationForm shrubForm("garden");
		RobotomyRequestForm robotForm("employee");
		PresidentialPardonForm pardonForm("criminal");
		
		std::cout << "ShrubberyCreationForm: " << shrubForm << std::endl;
		std::cout << "RobotomyRequestForm: " << robotForm << std::endl;
		std::cout << "PresidentialPardonForm: " << pardonForm << std::endl;
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*           Signing Attempts            *" << std::endl;
		std::cout << "****************************************" << std::endl;
		std::cout << "Low rank bureaucrat signing attempts:" << std::endl;
		lowRank.signForm(shrubForm);  //should succeed (grade 145)
		lowRank.signForm(robotForm);  //should fail (needs grade 72)
		lowRank.signForm(pardonForm); //should fail (needs grade 25)
		std::cout << std::endl;
		
		std::cout << "Mid rank bureaucrat signing attempts:" << std::endl;
		midRank.signForm(robotForm);  //should succeed (grade 50)
		std::cout << std::endl;
		
		std::cout << "High rank bureaucrat signing attempts:" << std::endl;
		highRank.signForm(pardonForm); //should succeed (grade 5)
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*         Execution Attempts            *" << std::endl;
		std::cout << "****************************************" << std::endl;
		
		std::cout << "Low rank bureaucrat execution attempts:" << std::endl;
		try {
			shrubForm.execute(lowRank);  //should succeed (grade 137)
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "Mid rank bureaucrat execution attempts:" << std::endl;
		try {
			robotForm.execute(midRank);  //should succeed (grade 45)
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "Attempting to execute unsigned form:" << std::endl;
		ShrubberyCreationForm unsignedForm("park");
		try {
			unsignedForm.execute(highRank);  //should throw FormNotSignedException
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "High rank bureaucrat execution attempts:" << std::endl;
		try {
			pardonForm.execute(highRank);  //should succeed (grade 5)
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		
		try {
			pardonForm.execute(midRank);  //should fail (needs grade 5)
		} catch (std::exception &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*         Bureaucrat::executeForm      *" << std::endl;
		std::cout << "****************************************" << std::endl;
		
		std::cout << "Using executeForm method:" << std::endl;
		highRank.executeForm(shrubForm);
		highRank.executeForm(robotForm);
		highRank.executeForm(pardonForm);
		midRank.executeForm(pardonForm);	// should fail (needs grade 5)
		midRank.executeForm(unsignedForm);	// should fail (not signed)
		std::cout << std::endl;
		
		std::cout << "****************************************" << std::endl;
		std::cout << "*         Multiple Robotomy Tests      *" << std::endl;
		std::cout << "****************************************" << std::endl;
		
		RobotomyRequestForm multiRobot("test subject");
		midRank.signForm(multiRobot);
		
		std::cout << "Attempting 5 robotomies to demonstrate randomness:" << std::endl;
		for (int i = 0; i < 5; i++) {
			std::cout << "Attempt " << (i + 1) << ": ";
			midRank.executeForm(multiRobot);
		}
	} 
	catch (const std::exception& e) {
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	
	return 0;
}
