/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:52:53 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/18 10:53:20 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	std::string const	name;		
	unsigned int	    grade;

public:
	Bureaucrat();
	Bureaucrat(std::string newName, unsigned int newGrade);
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
		
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	std::string		getName() const;
	unsigned int	getGrade() const;
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(AForm& form);
	void			executeForm(AForm const & form) const;
};
std::ostream&	operator<<(std::ostream&, const Bureaucrat&);
