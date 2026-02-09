/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:43:08 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/10 09:23:50 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"


int main(void)
{
	Bureaucrat		bureaucrat1("bureaucrat1", 10);
	Bureaucrat		bureaucrat2("bureaucrat2", 40);
	Bureaucrat		bureaucrat3("bureaucrat3", 5);
	ShrubberyCreationForm shrubbery("test");
	RobotomyRequestForm	robotomy("test");
	PresidentialPardonForm	presidential("test");
	std::cout << std::endl;
	AForm			*form = new ShrubberyCreationForm("test");

	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	std::cout << bureaucrat3 << std::endl;
	std::cout << std::endl;
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << presidential << std::endl;
	std::cout << std::endl;

	bureaucrat1.signAForm(shrubbery);
	bureaucrat1.executeForm(shrubbery);
	std::cout << std::endl;
	bureaucrat2.signAForm(robotomy);
	bureaucrat2.executeForm(robotomy);
	std::cout << std::endl;
	bureaucrat3.signAForm(presidential);
	bureaucrat3.executeForm(presidential);
	std::cout << std::endl;

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception attrapée (Bureaucrat grade trop haut): " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151); 
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapée (Bureaucrat grade trop bas): " << e.what() << std::endl;
	}

	try
	{
		ShrubberyCreationForm badForm("bad");
		bureaucrat1.executeForm(badForm); // pas signé
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapée (exécution sans signature): " << e.what() << std::endl;
	}
	delete (form);
	return (0);
}