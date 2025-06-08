/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 17:18:09 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:17:38 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include "Bureaucrat.hpp"
#include <fstream>

const unsigned int SIGN_GRADE = 145;
const unsigned int EXEC_GRADE = 137;

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation Form", SIGN_GRADE, EXEC_GRADE), target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
	: AForm("Shrubbery Creation Form", SIGN_GRADE, EXEC_GRADE), target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		// can't assign const members of AForm, only update the target
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsSigned()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	
	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	
	if (!outfile.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return;
	}
	
	// ASCII tree art
	outfile << "       ,|         " << std::endl;
	outfile << "      # (_        " << std::endl;
	outfile << "        _)|##     " << std::endl;
	outfile << "    ###/((_       " << std::endl;
	outfile << "         ))|####  " << std::endl;
	outfile << "       _((        " << std::endl;
	outfile << "  ####/  )|       " << std::endl;
	outfile << "       ,::'':     " << std::endl;
	outfile << "     (_______)    " << std::endl;
	outfile << "       |===|      " << std::endl;
	outfile << "       |===|      " << std::endl;
	outfile << "      |=====|     " << std::endl;
	
	outfile.close();
	std::cout << "Created " << filename << " with ASCII shrubbery" << std::endl;
}
