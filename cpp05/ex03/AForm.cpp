/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:58:57 by aneitenb          #+#    #+#             */
/*   Updated: 2025/03/18 16:21:51 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/********************************************************
*		constructors/copy assignment/destructor 		* 
*********************************************************/
AForm::AForm(): name("default"), gradeToSign(150), gradeToExecute(150), isSigned(false){
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, unsigned int gToSign, unsigned int gToExecute): name(name), gradeToSign(gToSign), gradeToExecute(gToExecute), isSigned(false){
	std::cout << "AForm " << name << " constructor called" << std::endl;
	if (gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(false)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(){
	std::cout << "AForm " << name << " destructor called" << std::endl;
}

/********************************************************
*			overload of insertion operator  			* 
*********************************************************/
std::ostream& operator<<(std::ostream& stream, const AForm& called)
{
	stream << called.getName() << ", AForm GRADE TO SIGN: " << called.getGradeToSign() << ", GRADE TO EXECUTE: " << called.getGradeToExecute() << ", IS SIGNED: " << called.getIsSigned();
	return stream;
}

/********************************************************
*					get functions						* 
*********************************************************/
std::string	AForm::getName() const{
	return name;
}

unsigned int	AForm::getGradeToSign() const{
	return gradeToSign;
}

unsigned int	AForm::getGradeToExecute() const{
	return gradeToExecute;
}

bool    AForm::getIsSigned() const{
	return isSigned;
}

/********************************************************
*					special functions					* 
*********************************************************/

void    AForm::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}