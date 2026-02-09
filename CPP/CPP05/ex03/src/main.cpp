/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:43:08 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/10 09:30:59 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Intern.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	// Test ShrubberyCreationForm
	try
	{
		AForm* shrub = intern.makeForm("ShrubberyCreationForm", "tree");
		boss.signAForm(*shrub);
		boss.executeForm(*shrub);
		delete (shrub);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (Shrubbery): " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Test RobotomyRequestForm
	try
	{
		AForm* robot = intern.makeForm("RobotomyRequestForm", "Robot");
		boss.signAForm(*robot);
		boss.executeForm(*robot);
		delete (robot);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (Robotomy): " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Test PresidentialPardonForm
	try
	{
		AForm* pardon = intern.makeForm("PresidentialPardonForm", "Paul");
		boss.signAForm(*pardon);
		boss.executeForm(*pardon);
		delete (pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (Pardon): " << e.what() << std::endl;
	}
	std::cout << std::endl;
	// Test mauvais nom de formulaire
	try
	{
		AForm* fail = intern.makeForm("UnknownForm", "nobody");
		delete fail;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception (UnknownForm): " << e.what() << std::endl;
	}

	return 0;
}