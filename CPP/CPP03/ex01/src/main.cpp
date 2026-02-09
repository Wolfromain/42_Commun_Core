/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:41:28 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 10:16:27 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("ClapTrap");
	ScavTrap scavtrap("ScavTrap");
	std::cout << std::endl;

	claptrap.attack("target");
	scavtrap.attack("target");
	std::cout << std::endl;
	claptrap.takeDamage(5);
	scavtrap.takeDamage(5);
	std::cout << std::endl;
	claptrap.beRepaired(3);
	scavtrap.beRepaired(3);
	std::cout << std::endl;
	scavtrap.guardGate();
	std::cout << std::endl;

	for (int i = 0; i < 9; i++)
	{
		claptrap.attack("target");
	}
	return (0);
}