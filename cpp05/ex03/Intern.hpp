/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneitenb <aneitenb@student.fi>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:08:06 by aneitenb          #+#    #+#             */
/*   Updated: 2025/06/08 17:18:11 by aneitenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Intern {
private:
	AForm* makeShrubberyCreationForm(const std::string& target) const;
	AForm* makeRobotomyRequestForm(const std::string& target) const;
	AForm* makePresidentialPardonForm(const std::string& target) const;

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm* makeForm(const std::string& formName, const std::string& target) const;

	class FormNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};
