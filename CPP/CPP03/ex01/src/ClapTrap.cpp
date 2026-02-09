/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:12:10 by rbouquet          #+#    #+#             */
/*   Updated: 2025/05/02 10:15:27 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(): _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap : Default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap : Default constructor called"<< std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	this->_name = cpy._name;
	this->_hitPoints = cpy._hitPoints;
	this->_energyPoints = cpy._energyPoints;
	this->_attackDamage = cpy._attackDamage;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f)
{
	this->_name = f._name;
	this->_hitPoints = f._hitPoints;
	this->_energyPoints = f._energyPoints;
	this->_attackDamage = f._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap : " << this->_name << " has been destroyed"<< std::endl;
	return ;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		if (this->_energyPoints <= 0)
		{
			std::cout << "ClapTrap : " << this->_name << " can't attack because he doesn't have enough energy" << std::endl;
			return ;
		}
		std::cout << "ClapTrap : " << this->_name << " can't attack because he's dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap : " << this->_name << " attacks " << target << ", causing " 
	<< this->_attackDamage << " points of damage!" << std::endl;
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap : " << this->_name << " is already dead" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
	std::cout << "ClapTrap : " << this->_name << " takes " << amount 
	<< " points of damage! hitPoint: " << this->_hitPoints << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		if (this->_energyPoints <= 0)
		{
			std::cout << "ClapTrap : " << this->_name << " can't be repaided becaause he doesn't have enough energy" << std::endl;
			return ;
		}
		std::cout << "ClapTrap : " << this->_name << " can't be repaired because he's dead" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << "ClapTrap : " << this->_name << " has been repaired for " 
	<< amount << " points! hitPoint: " << this->_hitPoints << std::endl;
	return ;
}