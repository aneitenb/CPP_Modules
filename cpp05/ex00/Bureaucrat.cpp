/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:52:46 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/18 09:52:10 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/********************************************************
*		constructors/copy assignment/destructor 		* 
*********************************************************/
Bureaucrat::Bureaucrat(): name("default"), grade(75){
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string newName, unsigned int newGrade): name(newName), grade(newGrade){
	std::cout << "Bureaucrat " << newName << " constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat copy assignment called" << std::endl;
	this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat " << name << " destructor called" << std::endl;
}

/********************************************************
*			overload of insertion operator  			* 
*********************************************************/
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& called)
{
	stream << called.getName() << ", bureaucrat GRADE: " << called.getGrade();
	return stream;
}

/********************************************************
*						exceptions  					* 
*********************************************************/
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

/********************************************************
*					get functions						* 
*********************************************************/
std::string	Bureaucrat::getName() const{
	return name;
}

unsigned int	Bureaucrat::getGrade() const{
	return grade;
}

/********************************************************
*					special functions					* 
*********************************************************/
void	Bureaucrat::incrementGrade(void){
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}  

void   Bureaucrat::decrementGrade(void){
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}
