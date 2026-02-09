/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:41:28 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 11:57:28 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FlagTrap.hpp"

// int main()
// {
// 	FlagTrap a("A");
// 	FlagTrap b("B");
	
// 	a.attack("B");
// 	b.takeDamage(20);
// 	b.attack("A");
// 	a.takeDamage(20);
// 	a.beRepaired(10);
// 	a.highFivesGuys();
// 	return (0);
// }


int main()
{
    // Création de deux FlagTrap
    FlagTrap robot1("Robot1");
    FlagTrap robot2("Robot2");

    // Test des attaques
    std::cout << "\n--- Test des attaques ---" << std::endl;
    robot1.attack("Robot2");
    robot2.takeDamage(30);

    robot2.attack("Robot1");
    robot1.takeDamage(25);

    // Test de la réparation
    std::cout << "\n--- Test de la réparation ---" << std::endl;
    robot1.beRepaired(15);
    robot2.beRepaired(20);

    // Test de la capacité spéciale
    std::cout << "\n--- Test de la capacité spéciale ---" << std::endl;
    robot1.highFivesGuys();
    robot2.highFivesGuys();

    return 0;
}