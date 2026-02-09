/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:43:08 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/10 09:17:15 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main (void)
{
	// Grade Too High
	try
	{
		std::cout << "A was created " << std::endl;
		Bureaucrat	A = Bureaucrat("A", 1);
		A.incrementGrade();
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Grade Too Low
	try
	{
		std::cout << "\nB was created " << std::endl;
		Bureaucrat	B = Bureaucrat("B", 150);
		B.decrementGrade();
		std::cout << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// OK
	try
	{
		std::cout << "\nC was created " << std::endl;
		Bureaucrat	C = Bureaucrat("C", 2);
		C.incrementGrade();
		std::cout << C << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//OK
	try
	{
		std::cout << "\nD was created " << std::endl;
		Bureaucrat	D = Bureaucrat("D", 150);
		std::cout << D << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}