/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:35 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/21 15:32:57 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal()
{
	this->_type = cpy._type;
}

Dog::~Dog()
{
	std::cout << "Dog : Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &f)
{
	this->_type = f._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog : WOUFFF" << std::endl;
}