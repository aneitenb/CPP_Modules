/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:14:50 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:17:32 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib> //rand()
#include <ctime>   //time()

const unsigned int SIGN_GRADE = 72;
const unsigned int EXEC_GRADE = 45;

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request Form", SIGN_GRADE, EXEC_GRADE), target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("Robotomy Request Form", SIGN_GRADE, EXEC_GRADE), target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		//can't assign const members of AForm, only update the target
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

std::string RobotomyRequestForm::getTarget() const {
	return this->target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	
	std::cout << "* DRILLING NOISES *" << std::endl;
	std::cout << "* DRRRRR * DRRRRR * DRRRRR *" << std::endl;
	
	if (std::rand() % 2) {
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy of " << this->target << " failed." << std::endl;
	}
}
