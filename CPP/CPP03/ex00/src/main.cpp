/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:30:11 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 10:15:01 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main()
{
	ClapTrap claptrap("ClapTrap");
	claptrap.attack("target");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);
	return (0);
}