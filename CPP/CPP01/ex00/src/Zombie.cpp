/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:08:50 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/25 12:05:48 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"


Zombie::Zombie(std::string str)
{
	this->name = str;
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
