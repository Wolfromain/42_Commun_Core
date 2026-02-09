/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:48:31 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/10 09:24:58 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm : default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm : destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : _target(cpy._target)
{
	// std::cout << "ShrubberyCreationForm : copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	// std::cout << "ShrubberyCreationForm : constructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &execute) const
{
	if (this->getSigned() == false)
		throw AForm::FormNotSignException();
	else if (execute.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error opening file" << std::endl;
		return ;
	}
	file << "      /\\       " << std::endl;
	file << "     /\\*\\      " << std::endl;
	file << "    /\\O\\*\\     " << std::endl;
	file << "   /0/\\/\\/\\    " << std::endl;
	file << "  /\\O\\/\\*\\/\\   " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\  " << std::endl;
	file << "/\\O\\/\\/0/\\/O/\\ " << std::endl;
	file << "      ||       " << std::endl;
	file << "      ||       " << std::endl;
	file << "      ||       " << std::endl;
}