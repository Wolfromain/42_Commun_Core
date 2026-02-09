/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:35 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/22 13:34:54 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog : Default constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal()
{
	this->_type = cpy._type;
	this->_brain = new Brain();
	std::cout << "Dog : Copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog : Destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &f)
{
	if (this != &f)
	{
		this->_type = f._type;
		delete this->_brain;
		this->_brain = new Brain();
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog : WOUFFF" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}
