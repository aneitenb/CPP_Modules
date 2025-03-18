/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:59:00 by aneitenb          #+#    #+#             */
/*   Updated: 2025/03/18 16:19:28 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	std::string const	name;		
	unsigned int const	gradeToSign;
	unsigned int const	gradeToExecute;
	bool				isSigned;
	

public:
	Form();
	Form(std::string newName, unsigned int gradeToSign, unsigned int gradeToExecute);
	Form(const Form&);
	Form& operator=(const Form&) = delete;
	~Form();
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too high!";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too low!";
			}
	};
	
	std::string		getName() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExecute() const;
	bool			getIsSigned() const;
	
	void			beSigned(Bureaucrat& bureaucrat);

};
std::ostream&	operator<<(std::ostream&, const Form&);