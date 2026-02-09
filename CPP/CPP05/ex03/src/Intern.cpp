/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:42:08 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/19 13:32:07 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern()
{
	// std::cout << "Intern : Default constructor called" << std::endl;
}

Intern::~Intern()
{
	// std::cout << "Intern : Destructor called" << std::endl;
}

Intern::Intern(const Intern &cpy)
{
	// std::cout << "Intern : Copy constructor called" << std::endl;
	*this = cpy;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	if (formName != "ShrubberyCreationForm" && formName != "RobotomyRequestForm" && formName != "PresidentialPardonForm")
		throw Intern::FormNotFoundException();
	switch (formName[0])
	{
		case 'S':
			return (new ShrubberyCreationForm(target));
		case 'R':
			return (new RobotomyRequestForm(target));
		case 'P':
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::FormNotFoundException();
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
