/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:12:41 by rbouquet          #+#    #+#             */
/*   Updated: 2025/03/28 16:10:29 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
	_weapon = NULL;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void	HumanB::attack() const
{
	if (_weapon)
		std::cout << _name << " attack with " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attack with nothing..." << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}