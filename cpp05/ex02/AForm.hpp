/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:16:36 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/18 10:11:28 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	std::string const	name;		
	unsigned int const	gradeToSign;
	unsigned int const	gradeToExecute;
	bool				isSigned;
	

public:
	AForm();
	AForm(std::string newName, unsigned int gradeToSign, unsigned int gradeToExecute);
	AForm(const AForm&);
	AForm& operator=(const AForm&) = delete;
	virtual ~AForm();
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
		
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
	};
	
	std::string		getName() const;
	unsigned int	getGradeToSign() const;
	unsigned int	getGradeToExecute() const;
	bool			getIsSigned() const;
	
	void			beSigned(Bureaucrat& bureaucrat);
	virtual void    execute(Bureaucrat const & executor) const = 0;
};
std::ostream&	operator<<(std::ostream&, const AForm&);