/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:20:09 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 12:05:39 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

void	Zombie::zombieName(std::string str)
{
	this->name = str;
}

Zombie::Zombie()
{
	std::cout << "A Zombie has been created" << std::endl;
}


Zombie::~Zombie()
{
	std::cout << this->name << " has been destroy" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}