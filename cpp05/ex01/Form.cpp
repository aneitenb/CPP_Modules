/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:58:57 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/18 10:03:34 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/********************************************************
*		constructors/copy assignment/destructor 		* 
*********************************************************/
Form::Form(): name("default"), gradeToSign(150), gradeToExecute(150), isSigned(false){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gToSign, unsigned int gToExecute): name(name), gradeToSign(gToSign), gradeToExecute(gToExecute), isSigned(false){
	std::cout << "Form " << name << " constructor called" << std::endl;
	if (gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other): name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(false)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(){
	std::cout << "Form " << name << " destructor called" << std::endl;
}

/********************************************************
*			overload of insertion operator  			* 
*********************************************************/
std::ostream& operator<<(std::ostream& stream, const Form& called)
{
	stream << called.getName() << ", Form GRADE TO SIGN: " << called.getGradeToSign() << ", GRADE TO EXECUTE: " << called.getGradeToExecute() << ", IS SIGNED: " << called.getIsSigned();
	return stream;
}

/********************************************************
*						exceptions  					* 
*********************************************************/
const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

/********************************************************
*					get functions						* 
*********************************************************/
std::string	Form::getName() const{
	return name;
}

unsigned int	Form::getGradeToSign() const{
	return gradeToSign;
}

unsigned int	Form::getGradeToExecute() const{
	return gradeToExecute;
}

bool    Form::getIsSigned() const{
	return isSigned;
}

/********************************************************
*					special functions					* 
*********************************************************/

void    Form::beSigned(Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}