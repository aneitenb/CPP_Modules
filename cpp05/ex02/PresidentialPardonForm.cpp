/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:12:21 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:17:23 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const unsigned int SIGN_GRADE = 25;
const unsigned int EXEC_GRADE = 5;

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", SIGN_GRADE, EXEC_GRADE), target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("Presidential Pardon Form", SIGN_GRADE, EXEC_GRADE), target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        //can't assign const members of AForm, only update the target
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
