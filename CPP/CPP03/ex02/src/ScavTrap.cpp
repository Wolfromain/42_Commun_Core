/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:58:41 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 10:17:03 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap : Default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap : Default constructor called"<< std::endl;
	return ;
} 

ScavTrap::ScavTrap(const ScavTrap &cpy)
{
	this->_name = cpy._name;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
{
	this->_name = f._name;
	this->_hitPoints = f._hitPoints;
	this->_energyPoints = f._energyPoints;
	this->_attackDamage = f._attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap : " << this->_name << " has been destroyed"<< std::endl;
	return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_energyPoints <= 0)
		{
			std::cout << "ScavTrap : " << this->_name << " can't attack because he doesn't have enough energy" << std::endl;
			return ;
		}
		std::cout << "ScavTrap: " << this->_name << " can't attack because he's dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap : " << this->_name << " attacks " << target << ", causing " 
	<< this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void	ScavTrap::guardGate()
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_energyPoints <= 0)
		{
			std::cout << "ScavTrap : " << this->_name << " can't guard because he doesn't have enough energy" << std::endl;
			return ;
		}
		std::cout << "ScavTrap: " << this->_name << " can't guard because he's dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap : " << this->_name << " is now in Gate keeper mode" << std::endl;
	this->_energyPoints--;
	return ;
}