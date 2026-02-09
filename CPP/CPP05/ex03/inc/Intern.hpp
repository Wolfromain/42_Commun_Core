/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 09:40:31 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/19 10:20:14 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
	public	:

		Intern();
		Intern(const Intern &cpy);
		~Intern();
		
		AForm *makeForm(std::string formName, std::string target);

		class FormNotFoundException : public std::exception
		{
			public :
				const char *what() const throw();
		};

	private	:
};

#endif