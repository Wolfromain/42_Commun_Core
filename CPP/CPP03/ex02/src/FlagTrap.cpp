/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:32:37 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 10:16:58 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FlagTrap.hpp"

FlagTrap::FlagTrap()
{
	std::cout << "FlagTrap : Default constructor called" << std::endl;
	return ;
}

FlagTrap::FlagTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FlagTrap : Default constructor called" << std::endl;
	return ;
}

FlagTrap::FlagTrap(const FlagTrap &cpy)
{
	this->_name = cpy._name;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return ;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &f)
{
	this->_name = f._name;
	this->_hitPoints = f._hitPoints;
	this->_energyPoints = f._energyPoints;
	this->_attackDamage = f._attackDamage;
	return (*this);
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap : " << this->_name << " has been destroyed" << std::endl;
}

void FlagTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_energyPoints <= 0)
		{
			std::cout << "FlagTrap : " << this->_name << " can't attack because he doesn't have enough energy" << std::endl;
			return ;
		}
		std::cout << "FlagTrap: " << this->_name << " can't attack because he's dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "FlagTrap : " << this->_name << " attacks " << target << ", causing " 
	<< this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void	FlagTrap::highFivesGuys()
{
	std::string	highFives;

	if (this->_hitPoints <= 0)
	{
		std::cout << "Flagtrap : " << this->_name << " can't high fives because he's dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "FlagTrap : " << this->_name << " can't high fives because he doesn't have enough energy" << std::endl;
		return ;
	}
	std::cout << "FlagTrap : " << this->_name << " request for a high fives !! (press enter to accept)" << std::endl;
	std::getline(std::cin, highFives);
	std::cout << "FlagTrap : " << this->_name << " high fives you !!" << std::endl;
	this->_energyPoints--;
}