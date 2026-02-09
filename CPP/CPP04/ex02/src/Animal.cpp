/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:14 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 15:32:42 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal()
{
	this->_type = "Animal";
	std::cout << "Animal : Default constructor called" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
	this->_type = cpy._type;
}

Animal::~Animal()
{
	std::cout << "Animal : Destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &f)
{
	this->_type = f._type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}