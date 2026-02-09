/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:43:08 by rbouquet          #+#    #+#             */
/*   Updated: 2025/06/10 09:20:47 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void)
{
	try {
		Bureaucrat b1("Paul", 1);
		Bureaucrat b2("Julie", 75);
		Bureaucrat b3("Mathis", 150);

		Form f1("TopSecret", 1, 1);
		Form f2("Standard", 100, 50);

		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		std::cout << std::endl;
		b1.signForm(f1); // devrait réussir
		b2.signForm(f1); // devrait échouer
		b3.signForm(f2); // devrait échouer
		b2.signForm(f2); // devrait réussir

		std::cout << "\n--- Affichage après signature ---\n";
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		std::cout << "\n--- Test exceptions ---\n";
		try {
			Bureaucrat b4("Erreur", 0); // Exception
		} catch (std::exception &e) {
			std::cout << "Exception attrapée : " << e.what() << std::endl;
		}
		try {
			Form f3("ErreurForm", 151, 10); // Exception
		} catch (std::exception &e) {
			std::cout << "Exception attrapée : " << e.what() << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << "Exception générale : " << e.what() << std::endl;
	}
	return 0;
}