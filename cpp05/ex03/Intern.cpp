/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:08:15 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:18:05 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}

const char* Intern::FormNotFoundException::what() const throw() {
	return "Error: Form type not found";
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	// Array of form names
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	
	// Array of function pointers to form creation methods
	AForm* (Intern::*formCreators[3])(const std::string&) const = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm
	};
	
	// Find the matching form
	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			AForm* form = (this->*formCreators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	throw FormNotFoundException();
}
