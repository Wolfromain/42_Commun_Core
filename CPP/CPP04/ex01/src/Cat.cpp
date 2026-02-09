/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbouquet <rbouquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:27:24 by rbouquet          #+#    #+#             */
/*   Updated: 2025/04/22 13:33:48 by rbouquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat : Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cpy) : Animal()
{
	this->_type = cpy._type;
	this->_brain = new Brain();
	std::cout << "Cat : Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat : Destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &f)
{
	if (this != &f)
	{
		this->_type = f._type;
		delete this->_brain;
		this->_brain = new Brain();
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat : MEWOOO" << std::endl;
}

Brain	*Cat::getBrain() const
{
	return (this->_brain);
}